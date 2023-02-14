#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<long long> v(n+1,0);
        map<int, vector<int>> r;
        for(int i=0;i<rides.size();i++) r[rides[i][0]].push_back(i);
        for(int i=1;i<n;i++)
        {
            v[i]=max(v[i],v[i-1]);
            for(int j=0;j<r[i].size();j++)
            {
                int el = r[i][j];
                v[rides[el][1]]=max(v[rides[el][1]],v[i]+rides[el][1]-rides[el][0]+rides[el][2]);
            }
        }
        v[n]=max(v[n],v[n-1]);
        return v[n];       
    }
};