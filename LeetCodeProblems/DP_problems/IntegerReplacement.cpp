#include <map>
using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        res = INT_MAX;
        traverse(n,0);
        return res;
    }
    
private:
    void traverse(long long n, int steps)
    {
        if(n==1) res = min(res, steps);
        else if(dp.find(n)==dp.end() || dp[n]>steps)
        {
            dp[n]=steps;
            if(n%2==0) traverse(n/2,steps+1);
            else
            {
                traverse(n+1,steps+1);
                traverse(n-1,steps+1);
            }
        }
    }
    
    int res;
    map<long long,int> dp;
};