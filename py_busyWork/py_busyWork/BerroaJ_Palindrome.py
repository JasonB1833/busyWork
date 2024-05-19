"""
Author name: Jason Berroa
Date: 2024/04/08
Program Name: BerroaJ_Palindrome.py
Purpose: take a string input from user, check if its a palindrome and output the answer
"""

def isPalindrome(text):
    # Wrapper func
    
    def toChars(text):
        # Converts a string to lowercase and removes spaces and punctuation.
        text = text.lower()
        return ''.join(char for char in text if char.isalpha())

    def isPal(chars):
        # Recursive function to check if a string of characters is a palindrome.
        if len(chars) <= 1:
            return True
        elif chars[0] != chars[-1]:
            return False
        else:
            return isPal(chars[1:-1])

    processed_text = toChars(text)
    return isPal(processed_text)

def main():
    # Main func
    user_input = input("Enter a string to check if it's a palindrome: ")

    print(f'is "{user_input}" a palindrome?')
    
    if isPalindrome(user_input):
        print("Yes, it's a palindrome.")
    else:
        print("No, it's not a palindrome.")

if __name__ == "__main__":
    main()
