#include <vector>
using namespace std;

class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int r = 0;
        for(int i=0;i<k;i++)
        {
            int minv = 0;
            int maxv = INT_MAX;
            int res = 0;
            while(minv<=maxv)
            {
                int avg= minv+(maxv-minv)/2;
                if(isWithinBudget(n,budget,composition[i],stock,cost,avg))
                {
                    res = avg;
                    minv = avg+1;
                }
                else maxv = avg-1;
            }
            r = max(r,res);
        }
        return r;
    }
private:
    bool isWithinBudget(int n, long long budget, vector<int>& composition, vector<int>& stock, vector<int>& cost, int num) {
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            long long tot = (long long)composition[i]*(long long)num;
            tot-=stock[i];
            tot = max(tot,(long long)0);
            sum+=(tot*(long long)cost[i]);
        }
        return sum<=budget;
    }
};