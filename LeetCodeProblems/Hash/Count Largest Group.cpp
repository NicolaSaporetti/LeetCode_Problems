#include <map>
using namespace std;

class Solution {
public:
    int countLargestGroup(int n) {
        map<int,int> m;
        map<int,int> t;
        for(int i=1;i<=n;i++)
        {
            int j=i;
            int g =0;
            while(j>0)
            {
                g+=j%10;
                j/=10;
            }
            m[g]++;
        }
        for(auto& [k,v] : m) t[v]++;
        return t.rbegin()->second;
    }
};