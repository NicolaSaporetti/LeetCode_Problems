using namespace std;
#include "Manacher's Algorithm.cpp"

class Solution {
public:
    int countSubstrings(string s) {
        auto r = manacher_even(s);
        int res = 0;
        for(auto e : r) res+=e/2;
        return res;
    }
};