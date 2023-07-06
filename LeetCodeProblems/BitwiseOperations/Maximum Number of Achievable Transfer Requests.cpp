#include <vector>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& r) {
        int sz = r.size();
        int result = 0;
        vector<int> balance;
        for(int i=0;i<(1<<sz);i++)
        {
            balance.assign(n,0);
            int num = 0;
            for(int j=0;j<sz;j++)
            {
                if(i & (1<<j))
                {
                    num++;
                    balance[r[j][1]]++;
                    balance[r[j][0]]--;
                }
            }
            bool isCorrect = true;
            for(int j=0;j<n && isCorrect;j++) if(balance[j]!=0) isCorrect = false;
            if(isCorrect) result = max(result,num);
        }
        return result;
    }
};