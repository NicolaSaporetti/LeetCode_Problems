#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto a: nums) mp[a]++;
        vector<int> v(mp.rbegin()->first-mp.begin()->first+1,0);
        for(auto& e : mp) v[e.first-mp.begin()->first]=e.first*e.second;
        for(int i=0;i<v.size();i++)
        {
            if(i>2) v[i]+=max(v[i-2],v[i-3]);
            else if(i>1) v[i]+=v[i-2];
        }
        if(v.size()>1) return max(v.back(),v[v.size()-2]);
        else return v.back();
    }
};