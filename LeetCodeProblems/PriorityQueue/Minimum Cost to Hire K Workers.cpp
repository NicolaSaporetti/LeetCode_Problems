#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> v;
        int sz = wage.size();
        for(int i=0;i<sz;i++) v.push_back({double(wage[i])/(double)quality[i],quality[i]});
        sort(begin(v),end(v));
        priority_queue<int> pq;
        int sum = 0;
        for(int i=0;i<k;i++)
        {
            sum+=v[i].second;
            pq.push(v[i].second);
        }
        double r = sum*v[k-1].first;
        for(int i=k;i<sz;i++)
        {
            sum-=(pq.top()-v[i].second);
            pq.pop();
            pq.push(v[i].second);
            r = min(r,sum*v[i].first);
        }
        return r;
    }
};