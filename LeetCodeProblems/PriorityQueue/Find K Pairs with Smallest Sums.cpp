#include <priority_queue>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int sz = nums1.size();
        int sz2 = nums2.size();
        vector<bool> vis(sz,false);
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({nums1[0]+nums2[0],0,0});
        for(int i=0;i<k && !pq.empty();i++)
        {
            int row = pq.top()[1];
            int col = pq.top()[2];
            pq.pop();
            res.push_back({nums1[row],nums2[col]});
            if(row+1<sz && !vis[row+1])
            {
                vis[row+1]=true;
                pq.push({nums1[row+1]+nums2[0],row+1,0});
            }
            if(col+1<sz2)
            {
                pq.push({nums1[row]+nums2[col+1],row,col+1});
            }
        }
        return res;
    }
};