class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Precompute left and right boundaries
        vector<int> rbounds(heights.size(), heights.size());
        vector<int> lbounds(heights.size(), -1);
        stack<int> rindices;
        stack<int> lindices;

        for (int i = 0; i < heights.size(); i++) {
            while (!rindices.empty() and heights[rindices.top()] > heights[i]) {
                int top = rindices.top();
                // pop the top element from stack
                rindices.pop();
                rbounds[top] = i;
            }
            rindices.push(i);
        }

        for (int i = heights.size()-1; i >= 0; i--) {
            while (!lindices.empty() and heights[lindices.top()] > heights[i]) {
                int top = lindices.top();
                lindices.pop();
                lbounds[top] = i;
            }
            lindices.push(i);
        }

        // Compute the largest rectangle area
        int max_area = 0;
        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            int area = height * (rbounds[i] - lbounds[i] - 1);
            printf("For idx: %d, rbound: %d, lbound: %d, area: %d\n", i, rbounds[i], lbounds[i], area);
            if (area > max_area) {
                max_area = area;
            }
        }
        return max_area;
    }
};
