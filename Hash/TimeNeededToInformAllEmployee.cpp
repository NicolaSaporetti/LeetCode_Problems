#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        maxTime = 0;
        setUpMap(manager);
        traverse(headID, manager, informTime, 0);
        return maxTime;
    }
private:
    void setUpMap(vector<int>& manager)
    {
        for(int i=0;i<manager.size();i++)
        {
            auto it = myM.find(manager[i]);
            if(it!=myM.end())
            {
                it->second.push_back(i);
            }
            else
            {
                vector<int> temp ={i};
                myM.insert(make_pair(manager[i],temp));
            }
        }
    }
    
    void traverse(int headID, vector<int>& manager, vector<int>& informTime, int time)
    {
        auto it = myM.find(headID);
        if(it!=myM.end())
        {
            for(int i=0;i<it->second.size();i++)
            {
                traverse(it->second[i], manager, informTime, time + informTime[headID]);
            }
        }
        else maxTime = max(maxTime, time);
    }
    
    map<int,vector<int>> myM;
    int maxTime;
};