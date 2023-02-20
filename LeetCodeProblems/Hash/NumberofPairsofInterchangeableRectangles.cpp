#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long res = 0;
        map<pair<long long,long long>, long long> m;
        int sz = rectangles.size();
        for(int i=sz-1;i>=0;i--)
        {
            long long val1 = rectangles[i][0];
            long long val2 = rectangles[i][1];
            long long gcd = __gcd(val1,val2);
            m[{val1/gcd,val2/gcd}]++;
        }
        for(auto& [key,val] : m)
        {
            res+=(val*(val-1))/2;
        }
        return res;
    }
};