#include <vector>
using namespace std;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        vector<pair<int,int>> a(transactions.size());
        long long tot = 0;
        long long res = 0;
        for(int i=0;i<transactions.size();i++)
        {
            a[i].first = transactions[i][1];
            a[i].second = transactions[i][0];
        }
        sort(a.begin(),a.end());
        for(int i=0;i<transactions.size();i++)
        {
            if(a[i].second>=a[i].first)
            {
                tot+=a[i].second;
                res=max(tot,res);
                tot-=a[i].first;
            }
            else res = max(res,tot+a[i].second);
        }
        return res;
    }
};