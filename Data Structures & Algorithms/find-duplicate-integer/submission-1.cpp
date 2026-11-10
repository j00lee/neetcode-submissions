class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Use a fast and slow pointer to detect cycle
        int fast = 0;
        int slow = 0;
        while (true) {
            fast = nums[fast];
            printf("fast: %d\n", fast);
            fast = nums[fast];
            printf("fast: %d\n", fast);
            slow = nums[slow];
            printf("slow: %d\n", slow);
            if (slow == fast) {
                break;
            }
        }
        
        int slow2 = 0;
        while (true) {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2) {
                return slow;
            }
        }
    }
};
