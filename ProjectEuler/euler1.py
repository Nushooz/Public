#!/usr/bin/python

'''
Created on Jul 24, 2014

@author: Mark Kaiser
'''

def euler1(x):
    sumof = 0
    for i in range(0,x):
        if i % 3 == 0:
            sumof += i
        elif i % 5 == 0:
            sumof += i
    print "The sum of all the multiples of 3 or 5 in", x, "is", sumof

def main():
    n = input("Please enter sum to number: ")
    euler1(n)
