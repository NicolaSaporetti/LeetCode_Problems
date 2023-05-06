#include <multiset>
#include <set>
using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(begin(salary),end(salary));
        double res = accumulate(begin(salary),end(salary),0);
        res-=salary[0];
        res-=salary.back();
        return res/(salary.size()-2);
    }
};