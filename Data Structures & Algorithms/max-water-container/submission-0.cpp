class Solution {
public:
    int maxArea(vector<int>& heights) {
        // Use two pointers
        // Only move the min of the two ptrs

        // Set up the pointers
        int l = 0;
        int r = heights.size() - 1;
        int max_area = 0;

        while (l < r) {
            // Calculate the current area
            int curr_area = (r - l) * min(heights[l], heights[r]);
            // printf("l: %d; r: %d; ", l, r);
            // printf("curr_area: %d\n", curr_area);
            if (curr_area > max_area) {
                max_area = curr_area;
            }
            // Move the min pointer inwards
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return max_area;
    }
};
