#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int right = maxSum;
        int left = maxSum/n;
        while(left<right)
        {
            int mid = left+(right-left+1)/2;
            int val = computeVal(mid,index,n);
            if(val>maxSum) right = mid-1;
            else left = mid;
        }
        return left;
    }
    
private:
    int computeVal(int mid, int index, int sz)
    {
        long long res = 0;
        long long rightI = min(sz-index,mid-1);
        res+= (rightI*(rightI+1))/2;
        res+=(mid-1-rightI)*rightI;
    
        long long leftI = min(index,max(0,mid-2));
        res+= (leftI*(leftI+1))/2;
        res+=(mid-2-leftI)*leftI;
        res+=sz;
        if(res>INT_MAX) return INT_MAX;
        else return res;
    }
};