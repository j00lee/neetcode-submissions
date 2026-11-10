class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        // Modified binary search
        // Every element is indexed 0,1,..(m * n - 1)

        int rows = matrix.size();
        int cols = matrix[0].size();
        int l = 0, r = (rows * cols - 1);

        while (l <= r) {
            int m = (l + r) / 2;
            int row = m / cols;
            int col = m % cols;
            if (target < matrix[row][col]) {
                r = m - 1;
            } else if (target > matrix[row][col]) {
                l = m + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};
