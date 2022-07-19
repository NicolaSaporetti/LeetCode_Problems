#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getval(int mid , vector<int>&arr)
    {
        int sum = 0;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(arr[i] > mid)
                sum+=mid;
            else
                sum+=arr[i];
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0 , h = *max_element(arr.begin(),arr.end());
        int ans = 0, min1 = INT_MAX;
        while(l<=h)
        {
            int mid = l + (h-l)/2;
            int k = getval(mid,arr);
            if(k==target)
            {
                return mid;
            }
            else if(k<target)
            {
                l = mid+1;
            }
            else
                h = mid -1;
            
            int j = abs(k - target);
            if(j<min1)
            {
                min1 = j;
                ans = mid;
            }
            else if(j==min1)
            {
                ans = min(ans , mid);
            }
        }
        return ans;
    }
};