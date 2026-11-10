class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // store stones in a max-heap
        priority_queue<int> pq;
        for (int stone: stones) {
            pq.push(stone);
        }
        while (pq.size() > 1) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if (first - second > 0) {
                pq.push(first - second);
            } 
        }
        if (pq.empty()) return 0;
        return pq.top();
    }
};
