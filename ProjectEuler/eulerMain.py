#!/usr/bin/python

'''
Created on Jul 24, 2014

@author: Mark Kaiser
'''

import euler1
import euler2
import euler3
import euler4
import euler5

def selection():
    print("Available Projects\n")
    print("1.     Multiples of 3 and 5")
    print("2.     Even Fibonacci numbers")
    print("3.     Largest prime factor")
    print("4.     Largest palindrome product")
    print("5.     Smallest multiple")
    try:
        choice = int(input("\nPlease choose a project number: "))
    except ValueError:
        print("That's not a number.\n")
        selection()

    if choice > 0 and choice <= 5:     #UPDATE FOR NEW PROBLEMS
        if choice == 1:
            euler1.main()
        elif choice == 2:
            euler2.main()
        elif choice == 3:
            euler3.main()
        elif choice == 4:
            euler4.main()
        elif choice == 5:
            euler5.main()
    else:
        print("C'mon now, that's not an option. Let's try again.\n")
        selection()

def main():
    selection()

main()