#include <vector>
using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto& e :cuboids) sort(begin(e),end(e),greater<int>());
        sort(begin(cuboids),end(cuboids),[](vector<int>& e1,vector<int>& e2){
            return (e1[0]>e2[0] || (e1[0]==e2[0] && (e1[1]>e2[1] || (e1[1]==e2[1] && e1[2]>=e2[2]))));});
        int sz = cuboids.size();
        vector<int> dp(sz,0);
        for(int i=0;i<sz;i++) dp[i]=cuboids[i][0];
        for(int i=0;i<sz;i++)
            for(int j=i+1;j<sz;j++)
                if(cuboids[i][1]>=cuboids[j][1] && cuboids[i][2]>=cuboids[j][2]) dp[j]=max(dp[j],dp[i]+cuboids[j][0]);
        return *max_element(begin(dp),end(dp));
    }
};