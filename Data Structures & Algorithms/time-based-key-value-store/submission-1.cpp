class TimeMap {
private: 
    map<string,vector<pair<int,string>>> m;


public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        if (m.find(key) == m.end()) {
            m[key] = {};
        }
        m[key].push_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        if (m.find(key) == m.end()) {
            return "";
        } 

        int l = 0, r = m[key].size()-1;
        string res = "";
        int max_time = 0;
        while (l <= r) {
            int mid = (l+r)/2;
            if (m[key][mid].first < timestamp) {
                if (m[key][mid].first > max_time) {
                    max_time = m[key][mid].first;
                    res = m[key][mid].second;
                }
                l = mid + 1;
            } else if (m[key][mid].first > timestamp) {
                r = mid - 1;
            } else {
                return m[key][mid].second;
            }
        }
        return res;

        // if (m[key][m[key].size()-1].first <= timestamp) {
        //     return m[key][m[key].size()-1].second;
        // } else {
        //     return "";
        // }
    }
};
