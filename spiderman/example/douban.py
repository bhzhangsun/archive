#! /usr/bin/env python3
# -*- coding: UTF-8 -*-

'文档注释：爬取豆瓣TOP250电影的名次、影片名称、年份、导演等字段。'


from bs4 import BeautifulSoup
import requests
import re
import json

base_url = 'https://movie.douban.com/top250'

def page_pass(start):
    url = base_url + '?start=' + str(start)
    ua = {
        "User-Agent":"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_3) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/80.0.3987.116 Safari/537.36"
    }

    html = requests.get(url, headers=ua)
    soup = BeautifulSoup(html.text, 'lxml')
    data = soup.select('#content > div > div.article > ol > li')
    result = []
    print('current page range: ' + str(start) + '->' + str(start+25))
    for item in data:
        pattern = re.compile(r'\n\s*导演: (.+?)\s*[主|&|\/].*\s+(\d+?)[\(|\s].*\/\s*(.+?)\s*\/\s*(.+?)\s*\n')
        title = item.select('div.info > div.hd > a')[0]
        body = item.select('div.info > div.bd')[0]
        # print(body.p.get_text())
        # print(pattern.match(body.p.get_text()).groups())
        query = pattern.match(body.p.get_text())
        if query is not None:
            groups = query.groups()
        else:
            print('WARN: regx parse failure!')
        
        # print(title.find_all('span'))
        # print(body.find_all('p'))
        # print(body.p.find_all(pattern))
        # print(type(body.p.get_text()))
        # print(groups[0])
        if len(body.find_all('p')) > 1:
            quote = body.find_all('p')[1].span.get_text()

        result.append({
            'rank': item.em.get_text(),
            'post_url': item.img['src'],
            'name': title.span.get_text(), # title.span只能获取title下的第一个span元素
            'english_name': title.find_all('span')[1].get_text()[3:],  # title.get_all获取title下的所有span元素
            'director': groups[0],
            'year': groups[1],
            'region': groups[2],
            'type': groups[3].split(' '),
            'rating_star': body.div.span['class'][0][6:-2],
            'rating_score': body.div.find_all('span')[1].get_text(),
            'num_rater': body.div.find_all('span')[3].get_text()[:-3],
            'quote': quote
        })
    return result


def top250():
    result = []
    for i in range(0, 250, 25):
        result.extend(page_pass(i))
    # result.append(page_pass(200))


    with open('example/storages/top250.json', 'w') as file:
        if file.write(json.dumps(result, indent=4, ensure_ascii=False)) < 0:
            print('error：write error')

    # try:
    #     file = 
    #     if file.write(json.dumps(result, indent=4, ensure_ascii=False)) < 0:
    #         print('error：write error')
    #     file.close()
    # except IOError as e:
    #     print(e)


if __name__ == '__main__':
    top250()

