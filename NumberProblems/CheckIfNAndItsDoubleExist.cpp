#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        for(int i=0;i<sz && arr[i]<=2*arr[sz-1];i++)
        {
            if(find(arr.begin(),arr.end(),2*arr[i])!=arr.end())
            {
                if(arr[i]!=0)
                {
                    return true;
                }
                else
                {
                    int lowI= lower_bound(arr.begin(),arr.end(),0)-arr.begin();
                    int highI = upper_bound(arr.begin(),arr.end(),0)-arr.begin();
                    if(highI-1-lowI>0) return true;
                }
            }
        }
        return false;
    }
};