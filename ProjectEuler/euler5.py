#!/usr/bin/python

'''
Created on Aug 4, 2014

@author: Mark Kaiser
'''

def euler5(x):
    isEvenlyDiv = False
    div = x  #start with lowest evenly divisible number
    print("Working...\n")

    while isEvenlyDiv == False:
        for n in range (2, x):   #cannot divide by 0, 1 always divides evenly into whole numbers
            if div % n == 0:
                isEvenlyDiv = True
            else:
                isEvenlyDiv = False #divisor was not capable of fully even division
                div += x            #increment our divisor by maximum dividend, as it is our last required result
                break

    print("The lowest possible evenly divisible number from 1 to", x, "is: ", div)

def main():
    dividend = int(input("Please enter the maximum dividend in which an integer can be evenly divided from: "))
    euler5(dividend)