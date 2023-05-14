#include <vector>
using namespace std;

class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> nums(n, 0), result;
        int c = 0;
        for (auto query : queries) {
            int index = query[0], color = query[1];
            if(index-1>=0 && nums[index]!=0 && nums[index-1]==nums[index]) c--;
            if(index-1>=0 && nums[index-1]==color) c++;
            if(index+1<n && nums[index]!=0 && nums[index+1]==nums[index]) c--;
            if(index+1<n && nums[index+1]==color) c++;
            nums[index] = color;
            result.push_back(c);
        }
        return result;
    }
};