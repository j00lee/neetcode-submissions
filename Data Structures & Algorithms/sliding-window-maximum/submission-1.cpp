class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Idea:
        // Step 1 -- sort nums
        // Step 2 -- 
        // whats the algorithmic complexity?

        vector<int> res = vector(nums.size()-k+1, -10001);
        
        // Sort nums in ascending order
        vector<pair<int,int>> zipped = vector(nums.size(),pair(0,0));
        for (int i = 0; i < nums.size(); i++) {
            zipped[i] = pair(nums[i], i);
        }
        sort(zipped.begin(), zipped.end());

        // Start from end of nums
        for (int i = nums.size()-1; i >= 0; i--) {
            int val = zipped[i].first;
            int idx = zipped[i].second;
            vector<int> windows = getWindows(idx, res.size(), k);
            for (int widx: windows) {
                res[widx] = max(val,res[widx]);
            }
        }
        return res;
    }

    vector<int> getWindows(int idx, int n, int k) {
        // generates list of windows to which given index belongs to
        vector<int> res = {};
        for (int i = 0; i < k; i++) {
            int widx = idx - i;
            if (widx >= 0 and widx < n) {
                res.push_back(widx);
            }
        }
        return res;
    }
};
