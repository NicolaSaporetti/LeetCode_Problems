#include <vector>
#include "SegmentTreeImmutable.cpp"
using namespace std;

class NumArray {
public:
    NumArray(vector<int>& nums) : st(nums) {}
    
    void update(int index, int val) {
        st.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return st.query(left,right);
    }

private:
    SegmentTreeImmutable<int> st;
};