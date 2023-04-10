#include <vector>
using namespace std;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int result = 0;
        int sz = nums.size();
        for(int i=0;i<sz;i++)
        {
            if(isPrime(nums[i][i])) result = max(result,nums[i][i]);
            if(isPrime(nums[i][sz-1-i])) result = max(result,nums[i][sz-1-i]);
        }
        return result;
    }
private:
    bool isPrime(int num)
    {
        int primef = 2;
        if(num==1) return false;
        while(num>=primef*primef)
        {
            if(num%primef==0) return false;
            else primef++;
        }
        return true;
    }
};