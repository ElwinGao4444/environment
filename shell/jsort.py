#!/usr/bin/env python
# -*- coding=utf8 -*-
"""
# Author: Elwin.Gao
# Created Time : Fri Mar  5 20:22:50 2021
# File Name: jsort.py
# Description:
"""

import json
import sys

if __name__ == '__main__':
    if not sys.stdin.isatty():
        data = sys.stdin.read()
        obj = json.loads(data)
    else:
        file = sys.argv[1]
        with open(file, 'r') as f:
            obj = json.load(f)
    print json.dumps(obj, sort_keys=True)

