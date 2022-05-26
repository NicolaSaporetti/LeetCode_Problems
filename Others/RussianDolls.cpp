#include <iostream>
#include <vector>
using namespace std;

bool LISfunction (vector<int>& i ,vector<int>& j) {
    return (i[0]==j[0])?i[1]>j[1]:i[0]<j[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),LISfunction);
        vector<int> dp;
        for (int i=0;i<envelopes.size();i++) {
            int height = envelopes[i][1];
            int left = lower_bound(dp.begin(), dp.end(), height) - dp.begin();
            cout<<"Left: "<<left<<endl;
            if (left == dp.size()) dp.push_back(height);
            dp[left] = height;
        }
        return dp.size();
    }
};

int main()
{
    Solution solution;
    return 0;
}