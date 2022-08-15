#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int sz=arr.size();
        if(sz == 1) return 0;
        int left =0;
        int right =sz;
        int minRemoval = INT_MAX;
        for(right=sz-1;right>=1;right--)
        {
            if(arr[right-1]>arr[right]) break;
        }
        if(right ==0) return 0;
        for(left=0;left<right;left++)
        {
            if(arr[left]>arr[left+1]) break;
        }
        cout<<"R: "<<right<<" L: "<<left<<endl;
        for(int i = left;i>=0;i--)
        {
            int index = lower_bound(arr.begin()+right,arr.end(),arr[i])-arr.begin();
            minRemoval = min(minRemoval, index-i-1);
        }
        minRemoval = min(minRemoval, right);
        return minRemoval;
    }
};