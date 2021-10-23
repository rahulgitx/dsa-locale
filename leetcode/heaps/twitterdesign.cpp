#include <bits/stdc++.h>
using namespace std;

class Twitter {
        queue<pair<int, int>> posts; 
    public:
        Twitter() {
            
        }
        
        void postTweet(int userId, int tweetId) {
            if(posts.size() == 10){
                posts.pop();
                posts.push({userId, tweetId});
            }
            else{
                posts.push({userId, tweetId});
            }
        }
        
        vector<int> getNewsFeed(int userId) {
            
        }
        
        void follow(int followerId, int followeeId) {
            
        }
        
        void unfollow(int followerId, int followeeId) {
            
        }
};