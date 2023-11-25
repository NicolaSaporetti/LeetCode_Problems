#include <vector>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> v(n);
        for(int i=0;i<n;i++) v[i]=(double)dist[i]/(double)speed[i];
        sort(begin(v),end(v));
        for(int i=0;i<n;i++) if(i>=v[i]) return i;
        return n;
    }
};