class Solution:
    def countBits(self, n: int) -> List[int]:
        # compute the sumBits of each number in range[n+1]
        allSumBits = [0] * (n + 1)
        for i in range(n + 1):
            allSumBits[i] = self.countBitsSingle(i)
        return allSumBits

    # Helper function to compute the number of 1's in the 
    # binary representation of a single number n
    def countBitsSingle(self, n: int) -> int:
        # Let's reason about this
        # Case: n = 0
        # sumBits = 0

        # basically, we have a 1 per digit that is "there" in the binary representation
        # could we just bit shift the num until we get 0? Each time, check if num is odd

        # Question: How to bit shift in Python? Use x >> y
        sumBits = 0
        while n != 0:
            # check if n is odd
            if n % 2 == 1:
                sumBits = sumBits + 1
            n = n >> 1
        return sumBits