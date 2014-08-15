#!/usr/bin/python

'''
Created on Jul 3, 2014

@author: Mark Kaiser
'''
def isPalindrome(product):
    test = str(product)
    firsthalf = ''
    secondhalf = ''
    even = False

    if len(str(product)) % 2 == 0: #length is even, no middle digit
        firsthalf, secondhalf = test[:len(test)/2], test[len(test)/2:]
        even = True
    else: #length is odd, ignore middle digit
        firsthalf, secondhalf = test[:(len(test)/2)], test[(len(test)/2)+1:]

    if str(firsthalf) == str(secondhalf)[::-1] and even: #reverse the second half for palindrome matching
        return True
    else:
        return False

def euler4(x): #input is length of factors to be multiplied
    length = x

    if x >= 2:
        startVal1 = ''
        startVal2 = ''
        palindromes = set()
        for _ in range (0, x): #need to maximize factors first, string manipulation seemed easiest
            startVal1 += '9'
            startVal2 += '9'

        for x in range(int(startVal1), -1, -1):   #traverse factors starting from greatest
            for y in range(int(startVal2), -1, -1):
                product = x * y
                if len(str(product)) > 2 and isPalindrome(product): #if string size is capable of palindrome and isPalindrome
                    palindromes.add(product)
    else:
        print "Length must be two or greater, single digit factors cannot make palindromes!"

    print "The largest palindrome made from the product of two" , length, "digit numbers is", max(palindromes)

def main():
    n = input("Please enter length of products for largest palindrome: ")
    euler4(n)
