#include <vector>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for(auto e : left) res = max(res,e);
        for(auto e : right) res = max(res,n-e);
        return res;
    }
};