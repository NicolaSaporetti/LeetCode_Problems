#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int sz = arr.size();
        int right_idx = lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int left_idx = right_idx-1;
        vector<int> result;
        for(int i=0;i<k;i++)
        {
            if(left_idx==-1 || ((right_idx!=sz) && abs(arr[left_idx]-x)>abs(arr[right_idx]-x))) result.push_back(arr[right_idx++]);
            else result.push_back(arr[left_idx--]);
        }
        sort(result.begin(),result.end());
        return result;
    }
};