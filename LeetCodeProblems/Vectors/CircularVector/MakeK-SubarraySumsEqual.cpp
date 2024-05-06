#include <vector>
using namespace std;

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int sz = arr.size();
        long long r = 0;
        k=__gcd(sz,k);
        for(int i=0;i<k;i++)
        {
            vector<int> v;
            for(int j=i;j<sz;j+=k) v.push_back(arr[j]);
            sort(begin(v),end(v));
            int sz2 = v.size();
            int median = (v[(sz2-1)/2]+v[sz2/2])/2;
            for(int i=0;i<sz2;i++) r+=(long long)abs(v[i]-median);
        }
        return r;
    }
};