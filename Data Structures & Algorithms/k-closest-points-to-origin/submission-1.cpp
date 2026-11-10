class Solution {
public:
    float calcDistance(float x, float y) {
        printf("distance for [%f,%f]: %f\n", x, y, sqrt((x*x) + (y*y)));
        return sqrt((x*x) + (y*y));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Same idea as k largest numbers in stream
        // use a max-heap to track the k smallest distances
        priority_queue<pair<float,vector<int>>> ksmallest;
        for (vector<int> coord: points) {
            int x = coord[0];
            int y = coord[1];
            float dist = calcDistance(x, y);
            ksmallest.push({dist, coord});
            if (ksmallest.size() > k) {
                printf("top of heap: %f\n", ksmallest.top().first);
                ksmallest.pop();
            }
        }
        
        vector<vector<int>> res;
        while (!ksmallest.empty()) {
            res.push_back(ksmallest.top().second);
            ksmallest.pop();
        }
        return res;
    }
};
