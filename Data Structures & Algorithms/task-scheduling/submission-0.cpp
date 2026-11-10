class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // gather counts of every task
        vector<int> counts = vector(26, 0);
        for (char task: tasks) {
            int idx = (int)task - (int)'A';
            counts[idx]++;
        }
        priority_queue<int> pq;
        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] > 0) pq.push(counts[i]);
        }

        int time = 0;
        queue<pair<int,int>> q;
        while (!q.empty() or !pq.empty()) {
            time++;

            // if pq is not empty, do some tasks
            if (!pq.empty()) {
                int freq = pq.top();
                pq.pop();
                freq--;
                if (freq != 0) q.push({freq, time+n});
            }
            
            if (!q.empty()) {
                // check for any tasks that have completed cooldown
                auto [freq, cooldown] = q.front();
                if (cooldown <= time) {
                    q.pop();
                    pq.push(freq);
                }
            }
        }
        return time;
    }
};
