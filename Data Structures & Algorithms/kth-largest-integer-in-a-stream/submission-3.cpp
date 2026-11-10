class KthLargest {
private:
    // min heap of top k nums
    priority_queue<int, vector<int>, greater<int>> topk; 
    int kth;
    int kay;

public:
    KthLargest(int k, vector<int>& nums) {
        kay = k;
        kth = 2000;
        for (int num: nums) {
            if (topk.size() < k) {
                topk.push(num);
                printf("kth: %d, num: %d\n", kth, num);
                kth = min(kth, num);
                printf("kth is now: %d\n", kth);
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
            printf("kth: %d, val: %d\n", kth, val);
            kth = min(kth, val);
            printf("kth is now: %d\n", kth);
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
