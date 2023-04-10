#include <vector>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26,0);
        for(int i=0;i<26;i++) v[i]=i+1;
        for(int i=0;i<chars.size();i++) v[chars[i]-'a']=vals[i];
        int res = 0;
        int temp =0;
        for(auto& e : s)
        {
            temp+=v[e-'a'];
            res=max(res,temp);
            if(temp<0) temp = 0;
        }
        return res;
    }
};