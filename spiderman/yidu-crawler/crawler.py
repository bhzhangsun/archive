#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

import requests
import re
import redis
import threading

class Crawler(threading.Thread) :
  """抓取器,将根url作为入口,以rooturl为入口,爬取所有url,提取其中有用的信息.
  其中爬取终止条件,通过内容与url进行判断,
  当格式满足小说目录页的格式时,记下url,一遍爬取内容
  """

  pool = redis.ConnectionPool(host="172.17.0.1")
  urlpfx = "hs_url_"
  count = 0
  
  def __init__(self, rooturl) :
    threading.Thread.__init__(self)
    self.start_url = self.__strip(rooturl)
    self.redis = redis.Redis(connection_pool=Crawler.pool)
 
  def run(self) :
    print("New Thread: ", self.start_url)
    self.prepares()
    self.__pass(self.start_url)
  

  def prepares(self) :
    """ 爬取前的处理 """
    pass

  def get(self, curl) :
    """ 获取网页 """
    try :
      page = requests.get(curl)
    except :
      print("Get this URL failure!", curl)
      return None

    page.encoding = 'utf-8'
    if page.status_code > 200 :
      return None
    else :
      return page.text

  def __pass(self, curl) :
    """ 主体函数,完成深度优先的url爬取"""
    if not self.available(curl) :
      return
    print("count: ", Crawler.count)
    content = self.get(curl)
    if content == None :
      return
    print("Add url: ", curl)
    self.redis.sadd(Crawler.urlpfx + self.start_url, curl)
    urls = self.processed(curl, content)
    if None == urls :
      # 被处理过,没有可提取的url,就不需要提取里面的url
      return
    
    # print("URLs", urls)
    for suffix in urls :

      if len(suffix) == 0 or suffix[0] == '#' :
        # 本页面内的锚点,忽略.
        continue
      elif -1 != suffix.find("//"):
        # 后直接作为url爬取
        newurl = suffix
      elif suffix[0] == '/' :
        # 拼接到根url,继续解析
          newurl = self.start_url + suffix
      else :
        # 拼接到当前url, 继续解析
        newurl = curl + '/' + suffix
      
      newurl = self.__strip(newurl)
      if self.available(newurl) and not self.redis.sismember(Crawler.urlpfx + self.start_url, newurl) :
        print("Step next level:", newurl)
        Crawler.count += 1
        self.__pass(newurl)
        Crawler.count -= 1
        
      print("This url exist or This url inavailable: ", newurl)
    


  def __strip(self, url) :
    """
    删除url中含有的多余'/'与尾部'/'
    除第一个"//"外,均为'/'
    """
    while url[-1] == '#' :
      url = url[0:-1]

    pos = url.find("//")
    if pos == -1 :
      return url

    while True :
      pos = url.find("//", pos + 1)
      if pos == -1 :
        break
      else :
        url = url[0:pos] + url[pos + 1:]
    return url

  

  def available(self, url) :
    """ url是否可用 , 返回True/False"""
    if -1 != url.find("avascript:") or -1 != url.find(".css") or -1 != url.find(".php"):
        # js, css等文件类型不做爬取
        return False

    if None != re.match(r'''.*//.*/.*\..*/.*\..*''', url) :
      return False

    return True

  def processed(self, url, content) :
    """ 处理目标内容
    返回True:当该内容为目标内容时,在本函数内被处理,无需在对其进行url爬取.
    返回False:该内容不是目标内容 
    """

    pattern = re.compile(r'''href=['"](.+?)['"]''')
    urls = pattern.findall(content)
    if len(urls) > 0 :
      return urls
    else :
      return None

