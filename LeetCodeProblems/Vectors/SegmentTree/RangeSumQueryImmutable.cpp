#include "SegmentTreeImmutable.hpp"
#include <vector>
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) : st(nums) {}
    
    int sumRange(int left, int right) {
        return st.query(left,right);
    }
private:
    SegmentTreeImmutable<int> st;
};