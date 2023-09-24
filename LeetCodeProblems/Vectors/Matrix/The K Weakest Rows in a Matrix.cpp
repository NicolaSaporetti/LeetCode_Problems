#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>> m;
        vector<int> res;
        for(int i=0;i<mat.size();i++)
        {
            m[count_if(begin(mat[i]),end(mat[i]),[](int elem){return elem==1;})].push_back(i);
        }
        auto it = m.begin();
        while(k>0)
        {
            for(int j=0;j<it->second.size() && k>0;j++,k--)
            {
                res.push_back(it->second[j]);
            }
            it++;
        }
        return res;
    }
};