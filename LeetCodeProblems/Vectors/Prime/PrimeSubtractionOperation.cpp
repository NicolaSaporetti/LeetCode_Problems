#include <vector>
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int sz = nums.size();
        int prev = 0;
        for(int i=0;i<sz;i++)
        {
            reduceNum(nums[i],prev);
            prev = nums[i];
            if(i>0 && nums[i]<=nums[i-1]) return false;
        }
        return true;
    }
private:
    void reduceNum(int& val, int base)
    {
        for(int j=val-1-base; j>1;j--)
        {
            if(isPrime(j))
            {
                val-=j;
                break;
            }
        }
    }
    
    bool isPrime(int num)
    {
        int i = 2;
        while(i*i<=num)
        {
            if(num%i==0) return false;
            i++;
        }
        return true;
    }
};