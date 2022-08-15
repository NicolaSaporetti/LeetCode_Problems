#include <iostream>
#include <vector>
using namespace std;

class NumArray {
private:
    vector<int> addition;
public:
    NumArray(vector<int>& nums) {
        addition.push_back(nums[0]);
        for(int i=1;i<nums.size();i++) addition.push_back(addition[i-1]+nums[i]);
    }
    
    int sumRange(int left, int right) {
        int value = addition[right];
        if(left>0) value-=addition[left-1];
        return value;
    }
};