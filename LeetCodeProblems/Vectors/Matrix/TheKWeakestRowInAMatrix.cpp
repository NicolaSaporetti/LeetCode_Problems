#include <iostream>
#include <vector>

using namespace std;

class Solution {
    map<int,vector<int>> myM;
    vector<int> getWeakestRows(int k)
    {
        vector<int> result;
        int count = 0;
        for(auto it=myM.begin();it!=myM.end() && count<k;it++)
        {
            for(int i=0;i<it->second.size() && count<k;i++,count++)
            {
                result.push_back(it->second[i]);
            }
        }
        return result;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> newV(1,0);
        int col_sz = mat[0].size();
        for(int i=0;i<mat.size();i++)
        {
            int j=col_sz-(upper_bound(mat[i].rbegin(),mat[i].rend(),0)-mat[i].rbegin());
            auto it = myM.find(j);
            if(it!=myM.end()) it->second.push_back(i);
            else
            {
                newV[0]=i;
                myM.insert(make_pair(j,newV));
            }
        }
        return getWeakestRows(k);
    }
};