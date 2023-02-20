#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> result;
        copy_if(begin(nums),end(nums),back_inserter(result),[](int elem){return elem%2==0;});
        copy_if(begin(nums),end(nums),back_inserter(result),[](int elem){return elem%2==1;});
        return result;
    }
};