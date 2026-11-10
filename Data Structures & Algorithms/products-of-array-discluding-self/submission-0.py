class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [1] * n
        suffix = [1] * n

        for i in range(n - 1):
            print(i+1)
            print(n - 2 - i)
            print()
            prefix[i + 1] = prefix[i] * nums[i]
            suffix[n - 2 - i] = suffix[n - 1 - i] * nums[n - 1 - i]
        
        output = [1] * n
        for i in range(n):
            output[i] = prefix[i] * suffix[i]
        print(prefix)
        print(suffix)
        return output