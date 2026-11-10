class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Get rid of all non-alphanumeric characters
        string = ""
        for c in s:
            if self.isValidChar(c):
                string += c

        # Reverse the string and check equality
        reverse = string[::-1]
        print(reverse)
        print(string)
        return reverse.lower() == string.lower()

    def isValidChar(self, c: str) -> bool:
        # c is an upper case character
        if ord(c) <= ord('Z') and ord(c) >= ord('A'):
            return True
        # c is a lower case character
        if ord(c) <= ord('z') and ord(c) >= ord('a'):
            return True
        # c is a number
        if ord(c) <= ord('9') and ord(c) >= ord('0'):
            return True

        return False