class Twitter {
private: 
    map<int,set<int>> fmap;
    map<int,vector<pair<int,int>>> pmap;
    int time = 0;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        if (pmap.find(userId) == pmap.end()) {
            pmap[userId] = {};
        }
        pmap[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        // get the most recent post from each followee and put in a heap
        // pop from heap until we get ten 
        // get list of people user follows
        set<int> followees;
        if (fmap.find(userId) != fmap.end()) {
            followees = fmap[userId];
        }
        followees.insert(userId);
        // get the 10 most recent posts
        map<int,int> pcounts;
        priority_queue<pair<int,pair<int,int>>> pq;
        for (int followee: followees) {
            if (pmap.find(followee) != pmap.end()) {
                auto [time, postId] = pmap[followee].back();
                pq.push({time,{postId,followee}});
                pcounts[followee] = 0;
            }
        }

        vector<int> res;
        int posts = 0;
        while (posts < 10 and !pq.empty()) {
            auto [time, p] = pq.top();
            int postId = p.first;
            int followee = p.second;
            pcounts[followee]++;
            pq.pop();
            res.push_back(postId);
            printf("pmap[followee].size()-1: %d, pcounts[followee]: %d, (pmap[followee].size()-1 - pcounts[followee]): %d\n", pmap[followee].size()-1, pcounts[followee], (pmap[followee].size()-1 - pcounts[followee]));
            if (pmap[followee].size()-1 >= pcounts[followee]) {
                printf("pushed to pq\n");
                auto [timenew, postIdnew] = pmap[followee][pmap[followee].size()-1 - pcounts[followee]];
                pq.push({timenew, {postIdnew, followee}});
            }
            posts++;
        }

        time++;
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (fmap.find(followerId) == fmap.end()) {
            set<int> s;
            fmap[followerId] = s;
        }
        fmap[followerId].insert(followeeId);
        time++;
    }
    
    void unfollow(int followerId, int followeeId) {
        if (fmap.find(followerId) != fmap.end()) {
            fmap[followerId].erase(followeeId);
        }
        time++;
    }
};
