#include <vector>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& A) {
        long long res = 0;
        int maxx = 0, maxxy = 0;
        for (int&a : A) {   
            res = max(res, 1LL * maxxy * a);
            maxxy = max(maxxy, maxx - a);
            maxx = max(maxx, a);
        }
        return res;
    }  
};