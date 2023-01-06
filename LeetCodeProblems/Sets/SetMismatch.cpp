#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m;
        vector<int> res(2,0);
        int sz = nums.size();
        for(int i=0;i<sz;i++) m[nums[i]]++;
        for(int i=1;i<=sz;i++)
        {
            if(m.find(i)==m.end()) res[1]=i;
            else if(m[i]==2) res[0]=i;
        }
        return res;
    }
};