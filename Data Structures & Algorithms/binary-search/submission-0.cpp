class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while (left < right) {
            printf("left: %d, right: %d\n", left, right);
            int mid = (left + right) / 2;
            if (target < nums[mid]) {
                right = mid-1;
            } else if (target > nums[mid]) {
                left = mid+1;
            } else {
                return mid;
            }
        }
        if (nums[left] == target) {
            return left;
        } else {
            return -1;
        }
    }
};
