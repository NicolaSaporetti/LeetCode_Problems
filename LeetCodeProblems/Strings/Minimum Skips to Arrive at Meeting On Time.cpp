#include <vector>
using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n=dist.size();
        vector<double> time(n);
        
        for(int i=0;i<dist.size();i++) time[i]=dist[i]*1.0/speed;
        vector<vector<double>> dp(n+1,vector<double>(n+1,INT_MAX));
        dp[0][0]=0.0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++) dp[i+1][j+1] = min(ceil(dp[i][j+1]- 0.00000001), dp[i][j]) +time[i];
        
        for(int i=0;i<n;i++){
            if(dp[n][i+1]<=hoursBefore) return i;
        }
        
        return -1;
    }
};