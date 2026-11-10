from collections import deque 

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        visited = set()

        def isValid(row, col) -> bool:
            return 0 <= row < n and 0 <= col < m and (row,col) not in visited and grid[row][col] == 1

        queue = deque()
        max_area = 0
        for i in range(n):
            for j in range(m):
                if isValid(i, j):
                    queue.append((i,j))
                    visited.add((i,j))
                    area = 0
                    while queue:
                        r, c = queue.popleft()
                        area += 1
                        for dr, dc in [(0,1),(0,-1),(1,0),(-1,0)]:
                            if isValid(r+dr, c+dc):
                                queue.append((r+dr, c+dc))
                                visited.add((r+dr,c+dc))
                    if area > max_area:
                        max_area = area
        return max_area

        