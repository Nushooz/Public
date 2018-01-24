#!/usr/bin/python

'''
Created on Jul 24, 2014

@author: Mark Kaiser
'''

def euler2(x):  #x is maximum Fibonacci value
    prevval = 1
    curval = 2
    sumof = 2     #2 is even in the given starting sequence numbers, so sum begins at 2

    nextval = prevval + curval

    while nextval <= x:
        if nextval % 2 == 0:
            sumof += nextval
        prevval = nextval
        nextval = curval + nextval
        curval = prevval

    print("The sum of the even-valued terms in this sequence is", sumof)

def main():
    n = int(input("Please enter the maximum Fibonacci range: "))
    euler2(n)
