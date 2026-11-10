class Solution:
    def isPalindrome(self, s: str) -> bool:
        # Use two pointers
        i = 0
        j = len(s) - 1
        while i <= j:
            if s[i].isalnum() and s[j].isalnum():
                if s[i].lower() != s[j].lower():
                    print(s[i])
                    print(s[j])
                    return False
                i += 1
                j -= 1
            else:
                if not s[i].isalnum():
                    i += 1
                if not s[j].isalnum():
                    j -= 1
        return True

    # def isPalindrome(self, s: str) -> bool:
    #     # Get rid of all non-alphanumeric characters
    #     string = ""
    #     for c in s:
    #         if self.isValidChar(c):
    #             string += c

    #     # Reverse the string and check equality
    #     reverse = string[::-1]
    #     print(reverse)
    #     print(string)
    #     return reverse.lower() == string.lower()

    # def isValidChar(self, c: str) -> bool:
    #     # c is an upper case character
    #     if ord(c) <= ord('Z') and ord(c) >= ord('A'):
    #         return True
    #     # c is a lower case character
    #     if ord(c) <= ord('z') and ord(c) >= ord('a'):
    #         return True
    #     # c is a number
    #     if ord(c) <= ord('9') and ord(c) >= ord('0'):
    #         return True

    #     return False
