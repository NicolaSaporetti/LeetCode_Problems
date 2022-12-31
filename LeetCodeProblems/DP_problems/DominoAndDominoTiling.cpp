#include <vector>
using namespace std;

class Solution {
public:
	int numTilings(int N) {
		vector<vector<long>> dp(N,vector<long>(3,0));
		int mod=1e9+7;
		if(N==1) return 1;
		dp[0][0]=1;
		dp[1][0]=2;
		dp[1][1]=1;
		dp[1][2]=1;
		for(int i=2;i<N;i++){
			dp[i][0]=(dp[i-2][0]+dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%mod;
			dp[i][1]=(dp[i-2][0]+dp[i-1][2])%mod;
			dp[i][2]=(dp[i-2][0]+dp[i-1][1])%mod;
		}  
		return dp[N-1][0];
	}
};