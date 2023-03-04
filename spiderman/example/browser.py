#! /usr/bin/env python3
#! -*- coding: utf-8 -*-

'文档注释：selenium模拟登录京东'


from selenium import webdriver
import selenium.webdriver.common.action_chains as chains
import sys

browser = webdriver.Chrome()
action = chains.ActionChains(browser)

base_url = 'https://passport.jd.com'

def login(name, key):
    browser.get(base_url + '/new/login.aspx')
    browser.implicitly_wait(3)
    rtab = browser.find_element_by_class_name('login-tab-r')
    action.click(rtab).perform()
    username = browser.find_element_by_id('loginname')
    password = browser.find_element_by_id('nloginpwd')
    username.send_keys(name)
    password.send_keys(key)

    submit = browser.find_element_by_id('loginsubmit')
    action.click(submit).perform()
    # print(browser.get_cookies())
    img = browser.find_element_by_css_selector('.JDJRV-bigimg img')
    print(img.get_attribute('src'))

    pass

if __name__ == '__main__':
    login('18792899171', 'zs2365619050bh')