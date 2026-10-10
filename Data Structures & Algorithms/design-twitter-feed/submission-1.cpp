class Twitter {

private:

int time;
unordered_map<int, unordered_set<int>> following;
unordered_map<int, vector<pair<int,int>>> tweets;

public:
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        following[userId].insert(userId);
        tweets[userId].push_back({time, tweetId});
        time++;

    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for (int user : following[userId]){

            auto& temp = tweets[user];
            for (auto& [timestamp, id] : temp){
                pq.push({timestamp, id});
                if (pq.size()>10) pq.pop();
            }

        }

        vector<int> ans;
        while (!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
