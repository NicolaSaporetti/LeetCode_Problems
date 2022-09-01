#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int result = 0;
        set<int> s;
        queue<int> q;
        for(int i=0;i<stones.size();i++) s.insert(i);
        for(int i=0;i<stones.size();i++)
        {
            if(s.find(i)==s.end()) continue;
            result++;
            q.push(i);
            s.erase(i);
            while(!q.empty())
            {
                int elem = q.front();
                queue<int> toRemove;
                q.pop();
                for(auto it = s.begin();it!=s.end();it++)
                {
                    if(stones[elem][0]==stones[*it][0] || stones[elem][1]==stones[*it][1])
                    {
                        q.push(*it);
                        toRemove.push(*it);
                    }
                }
                while(!toRemove.empty())
                {
                    s.erase(toRemove.front());
                    toRemove.pop();
                }
            }
        }
        return stones.size()-result;
    }
};