class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // bfs from every box that is land
        set<pair<int,int>> visited;
        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' and visited.find({i,j}) == visited.end()) {
                    printf("found unexplored land: x: %d, y:%d\n", i, j);
                    // do a dfs here
                    stack<pair<int,int>> st;
                    numIslands++;
                    st.push({i,j});
                    while (!st.empty()) {
                        auto [x,y] = st.top();
                        st.pop();
                        visited.insert({x,y});
            
                        vector<pair<int,int>> neighbs = getNeighbs(x, y, grid.size(), grid[0].size(), grid);
                        for (pair<int,int> neighb: neighbs) {
                            // printf("neighb at x: %d, y: %d\n", neighb.first, neighb.second);
                            if (visited.find(neighb) == visited.end()) st.push(neighb);
                        }
                    }
                }
            }
        }
        return numIslands;
    }

    vector<pair<int,int>> getNeighbs(int row, int col, int n, int m, vector<vector<char>>& grid) {
        vector<pair<int,int>> res;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i == 0 and j != 0 or i != 0 and j == 0) {
                    if (row + i >= 0 and row + i < n and col + j >= 0 and col + j < m and grid[row+i][col+j] == '1') {
                        res.push_back({row + i, col + j});
                    } 
                }
            }
        }
        printf("length of neighbs: %d\n", res.size());
        return res;
    }
};
