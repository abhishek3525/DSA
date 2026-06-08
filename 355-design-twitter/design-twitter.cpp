class Twitter {
    int n;
    vector<vector<bool>>people;
    vector<pair<int,int>>post;
public:
    Twitter() {
        n=5001;
        people.resize(n,vector<bool>(n,0));
    }
    
    void postTweet(int userId, int tweetId) {
        post.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        int n1=post.size();
        if(!n1) return {};
        int cnt=0;
        for(int i=n1-1;i>=0;i--){
            int celeb=post[i].first;
            int pst=post[i].second;
            if(celeb==userId or people[celeb][userId]){
                cnt++;
                ans.push_back(pst);
            }
            if(cnt==10) break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        people[followeeId][followerId]=1;
    }
    
    void unfollow(int followerId, int followeeId) {
        people[followeeId][followerId]=0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */