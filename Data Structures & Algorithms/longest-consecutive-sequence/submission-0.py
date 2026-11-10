class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        # Copy over nums into a set
        mySet = set(nums)

        # while set is not empty, take any element from
        # the set and try to build the longest subsequence
        # including this element
        maxSeq = 0
        while (mySet):
            elem = mySet.pop()
            lower = elem - 1
            upper = elem + 1
            print(elem)
            print(lower)
            print(upper)
            curSeq = 1
            # Build the longest sequence possible
            while ((lower in mySet) or (upper in mySet)):
                if lower in mySet:
                    mySet.remove(lower)
                    lower = lower - 1
                else: 
                    mySet.remove(upper)
                    upper = upper + 1
                curSeq = curSeq + 1
            # Have built the longest sequence; compare with maxSeq
            if curSeq > maxSeq:
                maxSeq = curSeq
        return maxSeq


        
