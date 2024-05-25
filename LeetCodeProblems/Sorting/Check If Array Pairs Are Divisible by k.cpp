#include <vector>
using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> v(k);
        for(auto e : arr)
        {
            if(e>=0) v[e%k]++;
            else v[(k-abs(e)%k)%k]++;
        }
        for(int i=1;i<(k+1)/2;i++) if(v[i]!=v[k-i]) return false;
        if(v[0]%2==1) return false;
        if(k%2==0 && v[k/2]%2==1) return false;
        return true;
    }
};