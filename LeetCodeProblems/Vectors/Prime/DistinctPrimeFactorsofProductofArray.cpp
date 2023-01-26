#include <vector>
using namespace std;

class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        v.assign(*max_element(begin(nums),end(nums))+1,0);
        for(auto& e : nums) computePrime(e);
        return count_if(begin(v),end(v),[](int elem){return elem>=1;});
    }
private:
    void computePrime(int el)
    {
        for(int i=2;el>0 && i*i<=el;i++)
        {
            while(el%i==0)
            {
                v[i]++;
                el/=i;
            }
        }
        if(el>1) v[el]++;
    }
    vector<int> v;
};