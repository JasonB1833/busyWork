"""
Author name: Jason Berroa
Date: 2024/03/12
Program Name: BerroaJ_twttr.py
Purpose: prompt user for a string, return that string with vowels removed
"""


def vowel_check(s):
    # init the Vowels list and the final string 
    vowels = ['a', 'e', 'i', 'o', 'u']
    final_S = ""
    # iterate through the string checking if its in the vowels list
    for i in s:
        if i.lower() not in vowels:
            final_S += i #adds the letters that arent vowels in a separate string
    return final_S


def main():# main method
    user = input("please input a test string: ")
    print(vowel_check(user))

    
if __name__ == "__main__":
    main()