#include "Z-function.cpp"
using namespace std;

class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int sz = word.size();
        int r = 0;
        vector<int> v = z_function(word);
        for(int i=k;i<sz;i+=k) if(v[i]==sz-i) return i/k;
        return sz/k+((sz%k)? 1 : 0);
    }
};