#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz = nums1.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long score =0;
        long long mult = 0;
        long long val = 0;
        map<int,int> m;
        vector<pair<long long,long long>> n(sz);
        for(int i=0;i<sz;i++) n[i]={nums2[i],nums1[i]};
        sort(begin(n),end(n));
        for(int i=0;i<k;i++)
        {
            val+=n[sz-1-i].second;
            mult = n[sz-1-i].first;
            pq.push(n[sz-1-i].second);
        }
        score=mult*val;
        for(int i=sz-k-1;i>=0;i--)
        {
            mult = n[i].first;
            val+=n[i].second;
            pq.push(n[i].second);
            val-=pq.top();
            pq.pop();
            score = max(score,mult*val);
        }
        return score;
    }
};