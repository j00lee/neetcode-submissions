class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # question: is the input sorted? No it is not
        myDict = {}
        for i in range(len(nums)):
            num = nums[i]
            if num not in myDict:
                myDict[num] = []
            myDict[num].append(i)

        
        # iterate over nums list, see if target - num is in myDict
        for i in range(len(nums)):
            num = nums[i]
            if target - num in myDict:
                j = myDict[target - num][0]
                if num == target - num:
                    if len(myDict[target - num]) == 1:
                        continue
                    j = myDict[target - num][1]
                return [i, j]

            