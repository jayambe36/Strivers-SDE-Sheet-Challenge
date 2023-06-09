from os import *    # import os module

from sys import *    # import sys module

from collections import *    # import collections module

from math import *    # import math module

from sys import stdin, stdout, setrecursionlimit    # import stdin, stdout and setrecursionlimit

def findTriplets(arr, n, k):    # findTriplets function to find triplets, which sums to k

    arr.sort()    # sort the array

    res=[]    # initialize result array

    for i in range(n-2):    # iterate over n-2 elements of array

        if arr[i]==arr[i-1] and i>0:    # check if value at i is same as value at i-1

            continue    # continue the iteration

        left=i+1    # initialize left pointer to i+1

        right=n-1    # initialize right pointer to n-1

        while left<right:    # iterate till left is less than right

            curr_sum=arr[i]+arr[left]+arr[right]    # curr_sum is the sum of values at i, left and right

            if curr_sum==k and [arr[i],arr[left],arr[right]] not in res:    # check if curr_sum is equal to k and triplet is not there in res array

                res.append([arr[i],arr[left],arr[right]])    # append the triplet to res array

                left+=1    # increment left by 1

                right-=1    # decrement right by 1

                

            elif curr_sum>k:    # check if curr_sum is greater than k

                right-=1    # decrement right by 1

            else:    # else body

                left+=1    # increment left by 1

    return res    # return res array

# Taking input using fast I/0.    # Taking input using fast I/0
def takeInput():    # takeInput function
    N = int(stdin.readline())    # read N from input
    arr = list(map(int, stdin.readline().strip().split(" ")))    # read array
    K = int(stdin.readline())    # read K from input
    return N, arr,K    # return N, arr and K

tc = int(input())    # read test case count
while tc > 0:    # iterate till tc is greater than 0
    N, arr,K = takeInput()    # takeInput
    ans = findTriplets(arr, N,K)    # find triplets which sum to K

    if len(ans) == 0:    # check if ans is empty
        stdout.write("-1\n")    # write -1 on console

    else:    # else body
        for i in ans:    # iterate over ans
            i.sort()    # sort the triplet
            stdout.write(str(i[0]) + " " + str(i[1]) + " " + str(i[2]) + "\n")    # write the triplet on console

    tc -= 1    # decrement tc by 1
