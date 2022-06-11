#include <iostream>
using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int lowBound = 0;
        int highBound = arr.size()-1;
        int index = (lowBound+highBound)/2;
        while(lowBound<highBound)
        {
            if(arr[index]-k-index<=0) lowBound = index+1;
            else highBound = index;
            index = (lowBound+highBound)/2;
        }
        if(arr[index]-k-index<=0)
        {
            return k+index+1;
        }
        else
        {
            return k+index;
        }
    }
};