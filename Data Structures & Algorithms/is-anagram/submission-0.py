class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # build s dict
        s_dict = {}
        for letter in s:
            if letter not in s_dict:
                s_dict[letter] = 0
            s_dict[letter] += 1

        # build t dict
        t_dict = {}
        for letter in t:
            if letter not in t_dict:
                t_dict[letter] = 0
            t_dict[letter] += 1

        return s_dict == t_dict