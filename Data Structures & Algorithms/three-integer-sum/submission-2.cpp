class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Step one: sort the list of nums
        std::sort(nums.begin(), nums.end());

        // Step two: for each num, check if it is in a triple
        set<vector<int>> solutions = {};
        for (int i = 0; i < nums.size() - 2; i++) {
            findDouble(nums, solutions, i, nums.size(), 0 - nums[i]);
        }
        // Step three: convert solutions set to vector

        vector<vector<int>> solutions_vector(solutions.begin(), solutions.end());
        return solutions_vector;
    }

    void findDouble(vector<int>& nums, set<vector<int>>& solutions, int startIdx, int endIdx, int target) {
        int i = startIdx + 1;
        int j = endIdx - 1;
        int curr_sum = nums[i] + nums[j];

        while (i < j) {
            if (curr_sum > target) {
                j--;
            } else if (curr_sum < target) {
                i++;
            } else {
                solutions.insert({0-target, nums[i], nums[j]});
                // move the pointers here
                i++;
                j--;
            }
            curr_sum = nums[i] + nums[j];
        }
    }
};
