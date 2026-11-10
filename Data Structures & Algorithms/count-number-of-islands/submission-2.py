from collections import deque

class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        m = len(grid[0])

        # Idea: Use BFS 

        # state tracking
        visited = set()
        to_check = deque()
        num_islands = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == "1":
                    #print("found land at: " + str(i) + ", " + str(j))
                    if (i,j) not in visited:
                        #print("we have found unvisited land at: " + str(i) + ", " + str(j))
                        to_check.append((i,j))
                        num_islands += 1

                        while to_check:
                            node = to_check.pop()
                            visited.add(node)
                            #print("Visiting node: " + str(node[0]) + ", " + str(node[1]))

                            neighbs = self.getNeighbs(grid, visited, node[0], node[1])
                            for neighb in neighbs:
                                to_check.append(neighb)
                                #print("Adding node: " + str(neighb[0]) + ", " + str(neighb[1]))
        return num_islands

    def getNeighbs(self, grid, visited, i, j):
        n = len(grid)
        m = len(grid[0])

        neighbs = set()
        dirs = [(0,1), (0,-1), (1,0), (-1,0)]
        for dx, dy in dirs:
            ip = dx + i
            jp = dy + j
            if ip >= 0 and ip < n:
                if jp >= 0 and jp < m:
                    if grid[ip][jp] == "1" and (ip,jp) not in visited:
                        neighbs.add((ip,jp))
        return neighbs

