#include <vector>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lowBound = 0;
        int highBound = arr.size()-1;
        int res = lowBound;
        while(lowBound<=highBound)
        {
            int mid = (lowBound+highBound)/2;
            if(arr[mid]-mid-k<=0)
            {
                lowBound = mid+1;
                res = mid;
            }
            else highBound = mid-1;
        }
        return (arr[res]-k-res<=0)? k+res+1 : k+res;
    }
};