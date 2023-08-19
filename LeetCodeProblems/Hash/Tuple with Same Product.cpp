#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        map<int,int> m;
        int sz = nums.size();
        int res = 0;
        for(int i=0;i<sz-1;i++)
            for(int j=i+1;j<sz;j++) m[nums[i]*nums[j]]++;
        for(auto& [k,v] : m) res+=4*(v-1)*v;
        return res;
    }
};