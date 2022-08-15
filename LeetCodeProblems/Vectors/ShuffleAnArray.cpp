#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> original;
    int size;
public:
    Solution(vector<int>& nums) {
        size = nums.size();
        for(int i=0;i<size;i++)
        {
            original.push_back(nums[i]);
        }
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        vector<int> temp = original;
        int unshaffled = size;
        for(int i = size - 1; i >= 0; --i){
            int pos = rand() % unshaffled;
            swap(temp[i], temp[pos]);
            unshaffled--;
        }
        return temp;
    }
};
