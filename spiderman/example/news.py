#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'文档注释：爬取头条新闻get_news'


from bs4 import BeautifulSoup
import requests
import re

def acquire():
    url='http://www.cntour.cn/'
    html = requests.get(url)
    soup = BeautifulSoup(html.text, 'lxml')
    data = soup.select('#main>div>div.mtop.firstMod.clearfix>div.centerBox>ul.newsList>li>a')
    print(data)
    for item in data:
        result = {
            'title':item.get_text(),
            'link':item.get('href'),
            'id': re.findall('\d+', item.get('href'))[0]
        }
        print(result)

if __name__ == '__main__':
    acquire()