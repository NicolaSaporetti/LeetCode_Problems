#include <priority_queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Twitter {
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        post[userId].push_back(tweetId);
        postTime[tweetId]=time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        if(post[userId].size()>0)
        {
            int id = post[userId].back();
            pq.push({postTime[id], userId, (int)post[userId].size()-1});
        }
        for(auto e : follower[userId])
        {
            if(post[e].empty()) continue;
            int id = post[e].back();
            pq.push({postTime[id],e, (int)post[e].size()-1});
        }
        vector<int> res;
        for(int i=0;i<10 && !pq.empty();i++)
        {
            auto el = pq.top();
            pq.pop();
            res.push_back(post[el[1]][el[2]]);
            if(el[2]>0)
            {
                int id = post[el[1]][el[2]-1];
                pq.push({postTime[id],el[1], el[2]-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }

    unordered_map<int,vector<int>> post;
    unordered_map<int,unordered_set<int>> follower;
    unordered_map<int,int> postTime;
    int time;
};