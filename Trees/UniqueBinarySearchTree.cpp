#include <iostream>
#include <vector>

class Solution {
private:
    vector<long long> catalan;
public:
    int numTrees(int n)
    {
        catalan.push_back(0);
        catalan.push_back(1);
        for(long long i=2;i<=n;i++)
        {
            catalan.push_back(((4*i-2)*catalan[i-1])/(i+1));
        }
        return catalan[n];
    }
};