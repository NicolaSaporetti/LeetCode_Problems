#include <vector>
using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) {
        int tot = a.size()+b.size();
        int res = INT_MAX;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(auto& e : a) v1[e-'a']++;
        for(auto& e : b) v2[e-'a']++;
        for(int i=0;i<26;i++) res = min(res,tot-v1[i]-v2[i]);
        int pt = b.size();
        for(int i=0;i<25;i++)
        {
            pt+=v1[i]-v2[i];
            res = min(res,pt);
        }
        pt = a.size();
        for(int i=0;i<25;i++)
        {
            pt+=v2[i]-v1[i];
            res = min(res,pt);
        }
        return res;
    }
};