#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'beautifulDays' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER i
#  2. INTEGER j
#  3. INTEGER k
#


def reverse(n):
    number = 0
    while ( n != 0):
       r = n % 10
       number = number * 10 + r
       n = n // 10
    return number
    
def beautifulDays(i, j, k):
    # Write your code here
    count = 0
    for date in range(i, j+1):
        rev_date = reverse(date)
        if (abs(date - rev_date) / k) == math.floor(abs(date - rev_date) / k):
            count += 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    i = int(first_multiple_input[0])

    j = int(first_multiple_input[1])

    k = int(first_multiple_input[2])

    result = beautifulDays(i, j, k)

    fptr.write(str(result) + '\n')

    fptr.close()
