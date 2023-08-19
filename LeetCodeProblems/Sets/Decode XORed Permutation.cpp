#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int sz = encoded.size()+1;
        vector<int> res(sz);
        unordered_set<int> n;
        for(int i=1;i<=sz;i++) n.insert(i);
        int t = 0;
        for(auto& e : encoded) t^=e;
        for(int i=encoded.size()-1;i>=0;i--)
        {
            n.erase(t);
            t^=encoded[i];
        }
        for(auto e : n)
        {
            bool cor = true;
            unordered_set<int> s;
            s.insert(e);
            res[0]=e;
            for(int j=0;j<sz-1 && cor;j++)
            {
                res[j+1]=res[j]^encoded[j];
                if(res[j+1]<1 || res[j+1]>sz || s.find(res[j+1])!=s.end()) cor = false;
                else s.insert(res[j+1]);
            }
            if(cor) return res;
        }
        return res;
    }
};