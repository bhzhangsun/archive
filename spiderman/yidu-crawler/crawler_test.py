#!/usr/local/bin/python3
# -*- coding: utf-8 -*-

from crawler import Crawler

craw = Crawler("https://www.biquke.com/")
print(craw.get("https://www.biquke.com/bq/0/499/"))
print(craw.available("javascript:") == False)
print(craw.available("https://www.biquke.com/bq/0/499/") == True)
print(craw.available("https://www.biquke.com/xuanhuan") == True)


print(craw.get("https://www.biquke.com/xuanhuan/"))

print(craw._Crawler__strip("https://www.biquke.com/bq//0/499/"))
craw.run()
