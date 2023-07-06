from os import *
from sys import *
from collections import *
from math import *

def wordBreak(arr, n, target):
    cache = {}
    def helper(i):
        if i >= len(target):
            return True

        if i in cache:
            return cache[i]

        for j in range(i, len(target)):
            subs = target[i:j+1]
            if subs in arr:
                if helper(j+1):
                    cache[j] = True
                    return cache[j]

        cache[i] = False
        return cache[i]

    return helper(0)