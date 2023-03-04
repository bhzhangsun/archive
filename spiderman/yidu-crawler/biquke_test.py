#!/usr/bin/python3
# -*- coding: utf-8 -*-
import redis
import biquke
from crawler import Crawler


b0 = biquke.Biquke0("https://www.biquke.com/")
b0.start()


redis = redis.Redis(connection_pool=Crawler.pool)


while True :
  temp = redis.blpop(b0.bookpfx + b0.start_url)[1]
  print(temp)
  url0 = bytes.decode(temp)
  print("take url is :", url0)
  bs0 = biquke.Biquke1(url0)

  temp = redis.blpop(b0.bookpfx + b0.start_url)[1]
  url1 = bytes.decode(temp)
  print("take url is :", url1)
  bs1 = biquke.Biquke1(url1)

  bs0.start()
  bs1.start()

  bs0.join()
  bs1.join()

b0.join()