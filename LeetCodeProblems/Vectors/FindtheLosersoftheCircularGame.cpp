#include <vector>
using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        int steps = k;
        vector<bool> vis(n,false);
        vector<int> res;
        int pos = 0;
        while(vis[pos]==false)
        {
            vis[pos]=true;
            pos=(pos+steps)%n;
            steps+=k;
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==false) res.push_back(i+1);
        }
        return res;
    }
};