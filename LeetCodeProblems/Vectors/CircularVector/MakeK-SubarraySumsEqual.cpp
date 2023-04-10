#include <vector>
using namespace std;

class Solution {
public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        long long sz = arr.size();
        long long res = 0;
        for(int i=0;i<k;i++)
        {
            vector<int> v;
            for(int j=i;arr[j]!=0;j=(j+k)%sz)
            {
                v.push_back(arr[j]);
                arr[j]=0;
            }
            if(!v.empty()) res+=computeDist(v);
        }
        return res;
    }
    
private:
    long long computeDist(vector<int>& v)
    {
        sort(begin(v),end(v));
        long long res = 0;
        int sz = v.size();
        long long mid = v[sz/2];
        for(auto& e : v) res+=abs(e-mid);
        return res;
    }
};