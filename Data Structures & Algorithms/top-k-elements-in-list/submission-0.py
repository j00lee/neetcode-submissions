class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:

        # Get the mappings of numbers to frequency
        freqMap = {}
        for num in nums:
            if num not in freqMap:
                freqMap[num] = 0
            freqMap[num] += 1

        # Convert to a mapping of frequency to numbers
        freqToNums = {}
        for num, freq in freqMap.items():
            if freq not in freqToNums:
                freqToNums[freq] = []
            freqToNums[freq].append(num)
        
        # Starting from n, find the k largest frequencies
        nextFreq = len(nums)
        sols = []
        while len(sols) < k:
            if nextFreq in freqToNums:
                sols = sols + freqToNums[nextFreq]
            nextFreq -= 1
        
        return sols
        