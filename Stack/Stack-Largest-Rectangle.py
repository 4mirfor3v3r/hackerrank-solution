#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'largestRectangle' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts INTEGER_ARRAY h as parameter.
#

def largestRectangle(heights):
    maxera = 0
    stack  = [] # (i,h)
    for i,h in enumerate(heights):
        start = i
        while stack and stack[-1][1] > h:
            index , height = stack.pop()
            maxera = max(maxera, (i-index)*height)
            start = index
        stack.append((start, h))
    for i, h in stack:
        maxera = max(maxera,h*(len(heights)-i))
    return maxera

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    h = list(map(int, input().rstrip().split()))

    result = largestRectangle(h)

    fptr.write(str(result) + '\n')

    fptr.close()
