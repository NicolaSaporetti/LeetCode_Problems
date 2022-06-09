#include <iostream>
#include <vector>
using namespace std;

class BookMyShow {
private:
    vector<int> rows;
    set<int> availableRows;
    int maxCol;
public:
    BookMyShow(int n, int m) {
        rows.resize(n);
        maxCol =m;
        for(int i=0;i<n;i++)
        {
            availableRows.insert(i);
            rows[i]=maxCol;
        }
    }
    
    vector<int> gather(int k, int maxRow) {
        vector<int> res;
        if(k>maxCol) return res;
        auto it=availableRows.begin();
        for(;it!=availableRows.end() && (*it)<=maxRow;it++)
        {
            if(rows[*it]>k)
            {
                res.push_back(*it);
                res.push_back(maxCol-rows[*it]);
                rows[*it]-=k;
                return res;
            }
            if(rows[*it]==k)
            {
                res.push_back(*it);
                res.push_back(maxCol-rows[*it]);
                rows[*it]=0;
                availableRows.erase(*it);
                return res;
            }
        }
        return res;
    }
    
    bool scatter(int k, int maxRow) {
        vector<int> res;
        vector<int> rowsToRemove;
        bool result=false;
        for(auto it=availableRows.begin();it!=availableRows.end() && *it<=maxRow && !result;it++)
        {
            if(k>rows[*it])
            {
                k-=rows[*it];
                rowsToRemove.push_back(*it);
            }
            else
            {
                rows[*it]-=k;
                k=0;
                if(rows[*it]==0)
                {
                    rowsToRemove.push_back(*it);
                }
                for(int i=0;i<rowsToRemove.size();i++)
                {
                    rows[i]=0;
                    availableRows.erase(rowsToRemove[i]);
                }
                result = true;
            }
        }
        return result;
    }
};