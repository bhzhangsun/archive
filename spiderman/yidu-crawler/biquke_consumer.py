#!/usr/local/bin/python3
# -*- coding: utf-8 -*-
import redis
import biquke
from crawler import Crawler

redis = redis.Redis(connection_pool=Crawler.pool)

while True :
  temp = redis.blpop("tq_book_https://www.biquke.com/")[1]
  print(temp)
  url0 = bytes.decode(temp)
  print("take url is :", url0)
  bs0 = biquke.Biquke1(url0)

  bs0.start()
  bs0.join()

