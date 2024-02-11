#include <vector>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> v(26,0);
        int r = 0;
        for(auto e : word) v[e-'a']++;
        sort(begin(v),end(v));
        reverse(begin(v),end(v));
        for(int i=0;i<26;i++)
        {
            r+=v[i]*((i/8)+1);
        }
        return r;
    }
};