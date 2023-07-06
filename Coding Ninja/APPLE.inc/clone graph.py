from os import *
from sys import *
from collections import *
from math import *

# Class for graph node is as follows:
class graphNode:
    def __init__(self, *args):
        if(len(args) == 0):
            self.data = 0
            self.neighbours = []

        elif(len(args) == 1):
            self.data = args[0]
            self.neighbours = []

        elif(len(args) == 2):
            self.data = args[0]
            self.neighbours = args[1]

    def __del__(self):
        self.neighbours.clear()


def cloneGraph(node):
    # Write your code here.
    cloned = {}
    def dfs(node):
        if node in cloned:
            return cloned[node]
        node_copy = graphNode(node.data)
        cloned[node] = node_copy
        for n in node.neighbours:
            node_copy.neighbours.append(dfs(n))
        return node_copy
    return dfs(node) if node else None
