#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int sz;
    
    void setupLeftVectors(vector<int>& nums, vector<int>& left)
    {
        int value = 0;
        left.resize(sz);
        for(int i=0;i<sz;i++)
        {
            value+=nums[i];
            left[i]=value;
        }
    }
    
    void setupRightVectors(vector<int>& nums, vector<int>& right)
    {
        int value = 0;
        right.resize(sz);
        for(int i=sz-1;i>=0;i--)
        {
            value+=nums[i];
            right[sz-i-1]=value;
        }
    }
    
    void checkMinOperation(int x, int& operations, vector<int>& first, vector<int>& second)
    {
        int remainingX = 0;
        int indexS = sz-1;
        for(int i=0;i<sz;i++)
        {
            remainingX = x-first[i];
            if(remainingX<0 || i+1>=operations) break;
            else if(remainingX ==0)
            {
                operations = min(operations,i+1);
            }
            else
            {
                if(indexS>sz-i-2) indexS =sz-i-2;
                while(indexS>0 && remainingX-second[indexS]<0) indexS--;
                if(indexS>0 && second[indexS]==remainingX)
                {
                    operations = min(operations,indexS+i+2);
                }
            }
        }
    }
    
public:
    int minOperations(vector<int>& nums, int x) {
        sz = nums.size();
        vector<int> left;
        vector<int> right;
        setupLeftVectors(nums,left);
        setupRightVectors(nums,right);
        int operations = INT_MAX;
        checkMinOperation(x,operations,left,right);
        checkMinOperation(x,operations,right,left);
        return (operations == INT_MAX)? -1 : operations;
    }
};