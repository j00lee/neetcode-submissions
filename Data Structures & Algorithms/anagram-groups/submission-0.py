class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # put each word into its own map
        indexMap = {}

        for i, word in enumerate(strs):
            wordMap = [0] * 26
            for letter in word:
                idx = ord(letter) - ord('a')
                wordMap[idx] += 1
            wordTuple = tuple(wordMap)
            if wordTuple not in indexMap:
                indexMap[wordTuple] = []
            indexMap[wordTuple].append(word)
        #     print(str(i))
        #     print(word)
        #     print(wordMap)
        # print(indexMap.values())
        return list(tuple(indexMap.values()))

        # # construct the groupings of anagrams
        # sols = []
        # for key, value in indexMap.items():
        #     partSols = []
        #     for index in value:
        #         partSols.append(strs[index])
        #     sols.append(partSols)

        # return sols

        