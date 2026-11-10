class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        # make an empty SET
        # for elem in nums
        #   if elem is already in SET, return true
        #   add elem to SET 
        # return false



        return len(set(nums)) != len(nums)

        mySet = set()
        for elem in nums:
            if elem in mySet: 
                return True
            mySet.add(elem)
        return False
