#include <vector>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        sort(begin(banned),end(banned));
        banned.erase(unique(begin(banned),end(banned)),end(banned));
        int res = 0;
        int pos = 0;
        for(int i=1;i<=n && maxSum>=i;i++)
        {
            if(pos>=banned.size() || banned[pos]!=i)
            {
                res++;
                maxSum-=i;
            }
            else pos++;
        }
        return res;
    }
};