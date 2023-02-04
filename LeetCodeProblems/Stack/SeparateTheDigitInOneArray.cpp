#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(auto& e : nums)
        {
            stack<int> t;
            while(e>0)
            {
                t.push(e%10);
                e/=10;
            }
            while(!t.empty())
            {
                res.push_back(t.top());
                t.pop();
            }
        }
        return res;
    }
};