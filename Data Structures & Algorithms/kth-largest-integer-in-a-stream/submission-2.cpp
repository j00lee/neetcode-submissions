class KthLargest {
private:
    // min heap of top k nums
    priority_queue<int, vector<int>, greater<int>> topk; 
    int kth;
    int kay;

public:
    KthLargest(int k, vector<int>& nums) {
        kay = k;
        kth = -2000;
        for (int num: nums) {
            if (topk.size() < k) {
                topk.push(num);
                kth = topk.top();
            } else { // we already have k nums
                if (num > kth) {
                    topk.push(num);
                    topk.pop();
                    kth = topk.top();
                }
            }
        }
    }
    
    int add(int val) {
        if (topk.size() < kay) {
            topk.push(val);
            kth = topk.top();
        } else { // we already have k nums
            if (val > kth) {
                topk.push(val);
                topk.pop();
                kth = topk.top();
            }
        }
        return kth;
    }
};
