#include <vector>
using namespace std;

class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;
        for(int i=0;i<sz-1;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                int n1 = get_dig(nums[i]);
                int n2 = nums[j]%10;
                if(__gcd(n1,n2)==1) res++;
            }
        }
        return res;
    }
private:
    int get_first_digit(int num)
    {
        while(num>=10)
        {
            num/=10;
        }
        return num;
    }
};