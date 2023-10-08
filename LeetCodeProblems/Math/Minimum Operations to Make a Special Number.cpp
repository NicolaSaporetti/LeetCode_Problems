#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(string num) {
        int sz = num.size();
        int res = count_if(begin(num),end(num),[](char c){return c=='0';})? sz-1 : sz;
        vector<vector<int>> v = {{0,0},{2,5},{5,0},{7,5}};
        for(int i=1;i<4;i++)
        {
            int j=1;
            for(int t=sz-1;t>=0;t--)
            {
                if(num[t]-'0'==v[i][j]) j--;
                if(j==-1)
                {
                    res = min(res,sz-t-2);
                    break;
                }
            }
        }
        int j=1;
        for(int t=sz-1;t>=0;t--)
        {
            if(num[t]-'0'==v[0][j]) j--;
            if(j==-1)
            {
                if(t>0) res = min(res,sz-t-2);
                break;
            }
        }
        return res;
    }
};