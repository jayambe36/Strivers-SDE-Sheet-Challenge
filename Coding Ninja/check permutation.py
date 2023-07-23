from os import *
from sys import *
from collections import *
from math import *

"""
    Time complexity: O(N)
    Space complexity: O(Number of different characters).

    Where 'N' is the length of the string.
"""

NO_OF_CHARS = 256

def areAnagram(str1, str2):
    # Create a count array and initialize all values as 0.
    hash = [0 for i in range(NO_OF_CHARS)]

    n1 = len(str1)
    n2 = len(str2)
    # If length of both strings is not same, then they cannot be anagram.
    if (n1 != n2):
       return False
    
    """
       For each character in input strings, 
       increment count in the corresponding count array.
    """
    for i in range(n1):
        hash[ord(str1[i])] += 1
        hash[ord(str2[i])] -= 1
        i += 1

    # Check if all values in hash array are 0.
    for i in range(NO_OF_CHARS):
        if (hash[i] != 0):
            return False
    
    return True