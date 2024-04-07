#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        multiset<int> s;
        for(auto r : matrix) for(auto c : r) s.insert(c);
        auto it = s.begin();
        for(int i=0;i<k-1;i++) it++;
        return *it;
    }
};