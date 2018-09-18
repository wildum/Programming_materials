import math
import os
import random
import re
import sys

def checkAnagram(sub1, sub2):
    i=0
    asub1 = [0]*26
    asub2 = [0]*26
    while i < len(sub1):
        asub1[ord(sub1[i])-97] += 1
        asub2[ord(sub2[i])-97] += 1
        i += 1
    for j in range(26):
        if asub1[j] != asub2[j]:
            return False
    return True
        
def sherlockAndAnagrams(s):
    ans=0
    for f in range(1,len(s)):
        for i in range(len(s)-f):
            sub1 = s[i:i+f]
            for j in range(i+1,len(s)-f+1):
                sub2 = s[j:j+f]
                if checkAnagram(sub1, sub2):
                    ans += 1
    return ans