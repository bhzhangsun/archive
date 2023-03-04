#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

from book import Book

book = Book("https://www.biquke.com/files/article/image/0/499/499s.jpg",
            "https://www.biquke.com/bq/0/499/",
            "最强弃少",
            "鹅是老五",
            "都市小说",
            "连载中",
            "叶默趁着下课的时候，急匆匆的跑进一个没人的小胡同，第一件事就是扒下自己的裤子，其实他只是想查看一下自己的小鸡鸡而已......",
            2270)
try :
  book.record2mysql(host="123.207.41.109", password="MYSQL@yidu", database="yidu_docxor_cn", user="yidu_docxor_cn")
except :
  print("record failure!")

print(book.chapter_name(3))
print(book._Book__makejson()) 
