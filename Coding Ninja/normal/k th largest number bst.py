from os import *
from sys import *
from collections import *
from math import *
import heapq

def KthLargestNumber(root, k):

    arr=[]

    q=[root]

    while q:

        node=q.pop(0)

        val=node.data

        if len(arr)<k:

            heapq.heappush(arr,val)

        else:

            heapq.heappush(arr,val)

            heapq.heapify(arr)

            heapq.heappop(arr)

        if node.left:

            q.append(node.left)

        if node.right:

            q.append(node.right)

    if len(arr)<k:

        return -1

    return arr[0]