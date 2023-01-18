#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        map<long long,long long> m;
        long long res = 0;
        for(auto& e : nums) m[e]++;
        while(k>0)
        {
            long long el = m.rbegin()->first;
            long long num = m.rbegin()->second;
            m.erase(el);
            if(num>k)
            {
                res+=(k*el);
                k=0;
            }
            else
            {
                res+=(num*el);
                k-=num;
            }
            m[el/3+((el%3==0)? 0 : 1)]+=num;
        }
        return res;
    }
};