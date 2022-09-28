#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> lr(n, n-1), rl(n, 0);
        
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            while(!s.empty() and nums[i] < nums[s.top()]) {
                lr[s.top()] = i-1;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n - 1; ~i; --i) {
            while(!s.empty() and nums[i] < nums[s.top()]) {
                rl[s.top()] = i+1;
                s.pop();
            }
            s.push(i);
        }
        for(int i = 0; i < n; ++i) {
            long long length = lr[i] - rl[i] + 1;
            if(1LL * nums[i] * length > threshold) return length;
        }
        
        return -1;
    }
};