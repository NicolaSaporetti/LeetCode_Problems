#include <vector>
using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        int i=0;
        for(;i<nums.size();i++)
        {
            if(isPrime(nums[i])) break;
        }
        int j= nums.size()-1;
        for(;j>=0;j--)
        {
            if(isPrime(nums[j])) break;
        }
        return j-i;
    }
    
    bool isPrime(int num)
    {
        int i = 2;
        if(num==1) return false;
        while(i*i<=num)
        {
            if(num%i==0) return false;
            i++;
        }
        return true;
    }
};