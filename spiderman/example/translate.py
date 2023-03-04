#!/usr/bin/env python3
# -*- coding: utf-8 -*-

'文档注释：提供翻译功能函数translate'
'@word: 要翻译的文字，5000个以内，大于这个长度会被截断'
'@return: 返回要翻译的语言'

import requests
import json
import sys
from news import acquire
# result = requests.get('http://www.baidu.com')
# print(result.text)

# acquire()

def translate(word=''):
    url = 'http://fanyi.youdao.com/translate_o?smartresult=dict&smartresult=rule'
    form = {
        'i': word,
        'from': 'zh-CHS',
        'to': 'en',
        'smartresult': 'dict',
        'client': 'fanyideskweb',
        'salt': '15822087619299',
        'sign': '9e44c16e2768e4fb096327996f559fe2',
        'ts': '1582208761929',
        'bv': '2ec76c77ac6f11d307caccc0a01ccded',
        'doctype': 'json',
        'version': '2.1',
        'keyfrom': 'fanyi.web',
        'action': 'FY_BY_REALTlME',
        'typoResult':'false'
    }

    response = requests.post(url, form)
    content = json.loads(response.text)
    print(content)

if __name__ == '__main__':
    text = ''
    if len(sys.argv) > 1:
        text = sys.argv[1]
    translate(text)