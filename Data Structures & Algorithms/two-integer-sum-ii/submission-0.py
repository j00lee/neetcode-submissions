class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        # My baby is so cute
        # He so amazed by simpoh technologies

        left = 0
        right = len(numbers) - 1
        sm = numbers[left] + numbers[right]
        while sm != target:
            if sm < target:
                left += 1
            else:
                right -= 1
            sm = numbers[left] + numbers[right]
        return [left+1, right+1]
