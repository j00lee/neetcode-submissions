class Solution:

    def encode(self, strs: List[str]) -> str:
        # need to encode so that the length of each string is included in the output string
        # output = [number of strings] [len of string 1] ... [len of last string] [string 1] ... [last string]
        n = len(strs)
        # generate array of lengths of each string
        lens = [None] * (n+1)
        lens[0] = self.formatInt(n)
        for i in range(n):
            lens[i+1] = self.formatInt(len(strs[i]))

        # combine all lists of strings to one list
        for i in range(n):
            lens += strs[i]

        # join together all strings using str.join
        sol = "".join(lens)
        print(sol)
        return sol
    
    def formatInt(self, num: int) -> str:
        numStr = ""
        if num < 100:
            numStr = numStr + "0"
        if num < 10:
            numStr = numStr + "0"
        return numStr + str(num)


    def decode(self, s: str) -> List[str]:
        # Read the first integer -- the number of words
        n = int(s[:3])

        # Read the lengths of each word
        wordLens = [0] * n
        idx = 3
        for i in range(n):
            print(s[idx: idx + 3])
            wordLens[i] = int(s[idx: idx + 3])
            idx += 3
        
        # Extract each word
        words = []
        for i in range(n):
            words.append(s[idx: idx + wordLens[i]])
            idx += wordLens[i]
        
        return words


