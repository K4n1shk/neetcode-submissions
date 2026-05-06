class Twitter {
   public:
    int time;
    // user -> list of {time, tweetId}
    unordered_map<int, vector<pair<int, int>>> tweets;
    // follower -> set of followeres
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() { time = 0; }

    void postTweet(int userId, int tweetId) { tweets[userId].push_back({time++, tweetId}); }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        followMap[userId].insert(userId);

        for (int followee : followMap[userId]) {
            auto& userTweets = tweets[followee];

            for (int i = userTweets.size() - 1; i >= 0 && i >= (int)userTweets.size() - 10; i--) {
                maxHeap.push(userTweets[i]);
            }
        }
        vector<int> result;

        while (!maxHeap.empty() && result.size() < 10) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId) { followMap[followerId].insert(followeeId); }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }
};
