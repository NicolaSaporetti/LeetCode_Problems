#include <vector>

class Solution {
public:
    int numTrees(int n)
    {
        vector<long long> catalan;
        catalan.push_back(0);
        catalan.push_back(1);
        for(long long i=2;i<=n;i++)
        {
            catalan.push_back(((4*i-2)*catalan[i-1])/(i+1));
        }
        return catalan[n];
    }
};