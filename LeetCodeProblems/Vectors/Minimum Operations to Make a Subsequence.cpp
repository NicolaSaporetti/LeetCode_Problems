#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m;
        vector<int> stack;
        for (auto t : target)
            m[t] = m.size();
        for (auto n : arr) {
            auto it = m.find(n);
            if (it != end(m)) {
                if (stack.empty() || stack.back() < it->second)
                    stack.push_back(it->second);
                else
                    *lower_bound(begin(stack), end(stack), it->second) = it->second;
            }
        }
        return target.size() - stack.size();
    }
};