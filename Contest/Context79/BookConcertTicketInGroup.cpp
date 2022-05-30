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

int main()
{
    Solution solution;
    return 0;
}

class BookMyShow {
private:
    map<int,queue<int>> availableRows;
    int maxCol;
public:
    BookMyShow(int n, int m) {
        vector<int> temp;
        maxCol =m;
        for(int i=0;i<n;i++)
        {
            temp.push_back(i);
        }
        map.insert(pair<int,queue<int>(maxCol,temp));
    }
    
    vector<int> gather(int k, int maxRow) {
        //cout<<"Gather"<<endl;
        vector<int> res;
        if(k>maxCol) return res;
        map<int,vector<int>>:iterator selectedIt = availableRows.end();
        int minValue = maxRow+1;
        for(auto it=availableRows.lower_bound(k);it!=availableRows.upper_bound(k);it++)
        {
            if(it->second[0]<minValue)
            {
                selectedIt = it;
                minValue = it->second[0];
            }
        }
        if(availableRows!=availableRows.end())
        {
            int row = selectedIt->second.front();
            res.push_back(row);
            res.push_back(maxCol-selectedIt->first);
            selectedIt->second.pop();
            if(selectedIt->first>k)
            {
                int finalAvailability = selectedIt->first-k;
                //if a new element with same value is there push
            }
        }
        return res;
    }
    
    bool scatter(int k, int maxRow) {
        //cout<<"Scatter"<<endl;
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