#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> radix(100002);
        vector<int> result(nums.size(),0);
        int zero = 50001;
        for(auto& e : nums) radix[e+zero]++;
        int pos=0;
        for(int i=0;i<radix.size();i++)
        {
            for(int j=0;j<radix[i];j++)
            {
                result[pos++]=i-zero;
            }
        }
        return result;
    }
};