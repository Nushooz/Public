#!/usr/bin/python

'''
Created on Jul 24, 2014

@author: Mark Kaiser
'''

def euler3(x): #Determines max prime factor, input is number to find max prime of
    if float(x).is_integer() and x >= 2: #make sure we are dealing with a whole number that can have prime factors
        factors = []
        n = 2 #starting prime is 2
        while x > 1:
            while x % n == 0:
                factors.append(n)
                x /= n
            n += 1
        print "Prime Factors are: ", factors
        print "Maximum Prime Factor is: ", max(factors)
    else:
        print "Only whole numbers with primes factors(2 or greater) can be used!"


def main():
    n = input("Please input number to find maximum Prime Factor of: ")
    euler3(n)
