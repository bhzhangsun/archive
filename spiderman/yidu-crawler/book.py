#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

import hashlib
import json
import random
import mysql.connector

class Book(object) :
  '书, 提供向mysql中存储,序列化为json, 更新章节等功能.'

  def __init__(self, imageurl, realurl, name, author, category, status, descrip, cnum) :
    self.image_url = imageurl
    self.read_url = realurl
    self.name = name
    self.author = author
    self.category = category # 数组
    self.status = status
    self.chapter_num = cnum
    self.describe = descrip
    self.id = self.__makeid(name, author)
    self.offset = random.randint(6000, 6000000)



  def record2mysql(self, *args, **kwargs) :
    try :
      conn = mysql.connector.connect(*args, **kwargs)
    except mysql.connector.Error as e :
      print("mysql connect failure!", format(e))
      return
    cursor = conn.cursor()

    try:
      if self.status == "连载中" :
        st = "SERIAL"
      else :
        st = "FINISHED"
      sql = "INSERT INTO `yd_books` (`bk_id`, `bk_name`, `bk_author`, `bk_describe`, `bk_category`, `bk_status`, `bk_imgurl`, `bk_srclinks`, `bk_capnum`, `bk_offset`, `bk_time`) VALUES ('%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', %d, %d, CURRENT_TIMESTAMP);"
      sql = sql % (self.id, self.name, self.author, self.describe, self.category, st, self.image_url, self.read_url, self.chapter_num, self.offset)
      print(sql)
      cursor.execute(sql)
      conn.commit()
    except mysql.connector.Error as e:
      print("mysql insert info failure!", format(e))
      
    cursor.close()
    conn.close()

  def storege(self, filename) :
    pass

  def chapter_name(self, index) :
    fname = hashlib.md5(str.encode(str(self.offset + index))).hexdigest()
    return fname + ".md"

  def __makeid(self, name, author) :
    return hashlib.md5(str.encode(name) + b"@" + str.encode(author)).hexdigest()

  def __makejson(self) :
    info = {
      "id" : self.id,
      "image_url" : self.image_url,
      "read_url" : self.read_url,
      "author" : self.id,
      "category" : self.category,
      "status" : self.status,
      "chapter" : self.chapter_num,
      "describe" : self.describe,
      "offset" : self.offset
      }
    
    return json.dumps(obj=info, skipkeys=True, indent=4, ensure_ascii=False)
