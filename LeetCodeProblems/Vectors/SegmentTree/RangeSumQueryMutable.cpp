#include <vector>
#include "SegmentTree.cpp"
using namespace std;

class NumArray {
public:
    SegmentTree s;
    vector<int> v;
    NumArray(vector<int>& nums) : s(nums), v(nums) {}
    
    void update(int index, int val) {
        s.update(v[index]-val, index);
        v[index] = val;
    }
    
    int sumRange(int left, int right) {
        return s.sumRange(left,right);
    }
};