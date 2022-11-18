#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0;i<numbers.size()-1;i++)
        {
            int l = i+1;
            int r = numbers.size()-1;
            int res = l;
            while(l<=r)
            {
                int mid = l+(r-l)/2;
                if(target-numbers[i]<numbers[mid])
                {
                    r=mid-1;
                }
                else
                {
                    res = mid;
                    l = mid+1;
                }
            }
            if(target==numbers[i]+numbers[res]) return {i+1, res+1};
        }
        return {};
    }
};