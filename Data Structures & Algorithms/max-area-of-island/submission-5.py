from collections import deque 

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        visited = set()
        q = deque()
        max_area = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1 and (i,j) not in visited:
                    # we have found unexplored island
                    area = 0
                    q.append((i,j))

                    while q:
                        node = q.pop()
                        if node not in visited:
                            visited.add(node)
                            area += 1
                        #print("visited node: " + str(node[0]) + ", " + str(node[1]))

                        neighbs = self.getNeighbs(grid, visited, node[0], node[1])
                        for neighb in neighbs:
                            q.append(neighb)

                    #print("Area of island was: " + str(area))
                    max_area = max(max_area, area)
        return max_area

    def getNeighbs(self, grid, visited, i, j):
        n = len(grid)
        m = len(grid[0])

        neighbs = set()
        dirs = [(1,0),(-1,0),(0,1),(0,-1)]

        for dx, dy in dirs:
            ip = i + dx
            jp = j + dy

            if ip >= 0 and ip < n and jp >= 0 and jp < m:
                if grid[ip][jp] == 1 and (ip,jp) not in visited:
                    neighbs.add((ip,jp))

        return neighbs