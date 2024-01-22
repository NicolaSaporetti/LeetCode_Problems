#include <vector>
using namespace std;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        vector<int> h;
        for(auto& e : hBars) if(e!=n+2) h.push_back(e);
        vector<int> v;
        for(auto& e : vBars) if(e!=m+2) v.push_back(e);
        sort(begin(h),end(h));
        sort(begin(v),end(v));
        int maxh = 0;
        int mh = 0;
        int maxv = 0;
        int mv = 0;
        for(int i=1;i<h.size();i++)
        {
            if(h[i]-1==h[i-1]) mh++;
            else mh=0;
            maxh = max(maxh,mh);
        }
        for(int i=1;i<v.size();i++)
        {
            if(v[i]-1==v[i-1]) mv++;
            else mv=0;
            maxv = max(maxv,mv);
        }
        maxh+=2;
        maxv+=2;
        return min(maxh,maxv)*min(maxh,maxv);
    }
};