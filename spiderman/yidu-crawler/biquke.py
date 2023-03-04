#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

import re
import os
from book import Book
from crawler import Crawler
import redis

goalmode = r'''og:title" +content="(.*?)".*
.*og:description" +content="(.*?)".*
.*og:image" +content="(.*?)".*
.*og:novel:category" +content="(.*?)".*
.*og:novel:author" +content="(.*?)".*
.*og:novel:book_name" +content="(.*?)".*
.*og:novel:read_url" +content="(.*?)".*
.*og:novel:status" +content="(.*?)".*
.*og:novel:update_time" +content="(.*?)".*
.*og:novel:latest_chapter_name" +content="(.*?)".*
<dl>
(<dd><a +href="(.*?)" +title="(.*?)">.*).+
</dl>'''

class Biquke0(Crawler) :
  """
  www.biquke.com 主页->小说页 爬取的第一步
  """
  bookpfx = "tq_book_"
  

  def __init__(self, rooturl) :
    super().__init__(rooturl)

  def run(self):
    return super().run()

  def processed(self, url, content) :
    pattern = re.compile(goalmode, flags=re.S)
    res = pattern.findall(content)
    if (len(res) == 0) :
      return super().processed(url, content)

    #加入同步任务队列
    rds = redis.Redis(connection_pool=Crawler.pool)
    rds.lpush(Biquke0.bookpfx + self.start_url, url)
    print("加入任务队列", url)
    return None


class Biquke1(Crawler) :
  """
  www.biquke.com/../.. 小说页->章节内容 爬取的第二步
  """

  def __init__(self, rooturl) :
    self.idx = 0
    super().__init__(rooturl)

  def run(self):
    return super().run()
  
  def processed(self, url, content) :
    pattern = re.compile(goalmode, flags=re.S)
    res = pattern.findall(content)
    # print("res: ", res)
    if (len(res) != 0) :
      # 小说页
      info = res[0]
      if (len(info) < 11) :
        print("parse error")
        return None
      # menu = re.findall(r'''<dd><a +href="(.*?)" +title="(?:.*?)''', info[10], flags=re.S)
      menu = super().processed(url, info[10])
      # print("menu: ", menu)
  
      self.book = Book(imageurl=info[2], realurl=info[6], name=info[0], author=info[4],
        category=info[3], status=info[7], descrip=info[1], cnum=len(menu))

      self.book.record2mysql(host="172.17.0.1", password="MYSQL@yidu", database="yidu", user="yidu")

      self.prefix = "./book/" + self.book.id
      if not os.path.exists(self.prefix) :
        os.makedirs(self.prefix)
      
      # self.book.storege(self.prefix + "")
      return menu

    # 章节页
    field = re.findall(r'''<h1>(.*?)</h1>.*<div id="content">.(.*?).</div>''', content, flags=re.S)[0]
    # print(field)
    fname = self.book.chapter_name(self.idx)
    file = open(self.prefix + "/" + fname, "w")
    file.write("# " + field[0] + "\n" + field[1])
    file.close()
    self.idx += 1

    return None

