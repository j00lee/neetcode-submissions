class Solution:
    def climbStairs(self, n: int) -> int:
        # we handle the base cases: n = 1 and n = 2
        if n == 1: 
            return 1
        if n == 2:
            return 2
        # the recursive case: return f(n-1) + f(n-2)
        return self.climbStairs(n-1) + self.climbStairs(n-2)

    # Possible optimizations
    # Use memoization
    def climbStairsDP(self, n: int) -> int:
        # handle the base cases
        if n == 1 or n == 2:
            return 1
        # Initialize the memoization array
        numWays = [0] * n
        # Initialize the base cases: n = 1 and n = 2
        numWays[0] = 1
        numWays[1] = 1
        return climbStairsDPHelper(n, numWays)

    # DP Helper 
    def climbStairsDPHelper(self, n: int, numWays: list[int]) -> int:
        if numWays[n - 1] != 0:
            return numWays[n - 1]
        # Compute the subproblems
        numWays[n - 2] = climbStairsDPHelper(n - 1, numWays)
        numWays[n - 3] = climbStairsDPHelper(n - 2, numWays)
        return numWays[n - 2] + numWays[n - 3]