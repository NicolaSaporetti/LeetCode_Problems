#include <vector>
using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int sz = reward1.size();
        vector<pair<int,int>> dif(sz);
        int r = 0;
        for(int i=0;i<sz;i++) dif[i]={reward1[i]-reward2[i],i};
        sort(begin(dif),end(dif));
        for(int i=0;i<k;i++) r+=reward1[dif[sz-1-i].second];
        for(int i=k;i<sz;i++) r+=reward2[dif[sz-1-i].second];
        return r;
    }
};