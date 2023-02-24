#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;
        map<int,vector<int>> m;
        int sz = profits.size();
        for(int i=0;i<sz;i++) m[capital[i]].push_back(profits[i]);
        auto it = m.begin();
        do
        {
            while(it!=m.end() && w>=it->first)
            {
                for(int i=0;i<it->second.size();i++) pq.push(it->second[i]);
                it++;
            }
            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
            k--;
        } while(k>0);
        return w;
    }
};