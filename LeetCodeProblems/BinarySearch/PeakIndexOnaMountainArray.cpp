#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        while(left<right)
        {
            int mid = left+(right-left)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]) left = mid;
            else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]) right = mid;
            else return mid;
        }
        return -1;
    }
};