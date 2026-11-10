class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // kth largest element in array -- same idea as 
        // kth largest number in stream
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int num: nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};
