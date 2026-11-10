class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0, r = nums.size()-1;

        // int counter = 0;
        while (l <= r) {
            int m = (l + r) / 2;

            if (nums[l] < nums[m] and nums[l] < target and target < nums[m] or (nums[l] > nums[m] and (nums[l] < target or nums[m] > target))) {
                printf("FIRST nums[l]: %d, nums[m]: %d, nums[r]: %d\n", nums[l], nums[m], nums[r]);
                r = m - 1;
            } else if (nums[m] < nums[r] and nums[m] < target and target < nums[r] or (nums[m] > nums[r] and (nums[m] < target or nums[r] > target))) {
                printf("SECOND nums[l]: %d, nums[m]: %d, nums[r]: %d\n", nums[l], nums[m], nums[r]);
                l = m + 1;
            } else if (nums[l] == target) {
                printf("THIRD nums[l]: %d, nums[m]: %d, nums[r]: %d\n", nums[l], nums[m], nums[r]);
                return l;
            } else if (nums[m] == target) {
                printf("FOURTH nums[l]: %d, nums[m]: %d, nums[r]: %d\n", nums[l], nums[m], nums[r]);
                return m;
            } else if (nums[r] == target) {
                printf("FIFTH nums[l]: %d, nums[m]: %d, nums[r]: %d\n", nums[l], nums[m], nums[r]);
                return r;
            } else {
                printf("Didn't meet any of requirements\n");
                printf("nums[l]: %d, nums[m]: %d, nums[r]: %d\n", nums[l], nums[m], nums[r]);
                return -1;
            }
            // counter += 1; 
            // if (counter > 10) {
            //     break;
            // }
        }
        return -1;
    }
};
