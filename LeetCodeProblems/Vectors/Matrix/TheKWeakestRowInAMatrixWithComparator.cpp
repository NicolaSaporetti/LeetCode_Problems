#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    int soldiers;
    int row;
} myS;

struct comp {
    bool operator()(myS const & a, myS const & b) const {
        bool compare = false;
        if(a.soldiers < b.soldiers) compare = true;
        else if(a.soldiers == b.soldiers) compare = (a.row>b.row)? false: true;
        else compare = false;
        return compare;
    }
};

class Solution {
    set<myS, comp> myM;
    vector<int> getWeakestRows(int k)
    {
        vector<int> result;
        int count = 0;
        for(auto it=myM.begin();it!=myM.end() && count<k;it++)
        {
            count++;
            result.push_back(it->row);
        }
        return result;
    }
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> newV(1,0);
        int col_sz = mat[0].size();
        myS myStruct;
        for(int i=0;i<mat.size();i++)
        {
            int j=col_sz-(upper_bound(mat[i].rbegin(),mat[i].rend(),0)-mat[i].rbegin());
            myStruct.soldiers = j;
            myStruct.row = i;
            myM.insert(myStruct);
        }
        return getWeakestRows(k);
    }
};