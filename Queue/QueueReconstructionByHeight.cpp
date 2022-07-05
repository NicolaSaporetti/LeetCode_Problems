#include <iostream>
#include <priority_queue>
#include <map>
#include <vector>
using namespace std;

typedef pair<int, vector<int>> pi;

struct myComp {
    constexpr bool operator()(
        pair<int, vector<int>> const& a,
        pair<int, vector<int>> const& b)
    {
        return a > b;
    }
};

class Solution {
private:
    map<int,vector<vector<int>>> myM;
    priority_queue<pi,vector<pi>, myComp> pq;
    vector<vector<int>> results;
    int sz;
    
    void reduceVals(int val)
    {
        for(auto it = myM.begin();it!=myM.end();it++)
        {
            if(it->first<=val)
            {
                for(int i=0;i<it->second.size();i++)
                {
                    it->second[i][0]--;
                    if(it->second[i][0]==0)
                    {
                        vector<int> temp(2,0);
                        temp[1]=it->second[i][1];
                        pq.push(make_pair(it->first,temp));
                    }
                }
            }
            else break;
        }
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sz = people.size();
        vector<int> result (2,0);
        for(int i=0;i<sz;i++)
        {
            auto it = myM.find(people[i][0]);
            if(it!=myM.end())
            {
                vector<int> temp;
                temp.push_back(people[i][1]);
                temp.push_back(people[i][1]);
                it->second.push_back(temp);
            }
            else
            {
                vector<vector<int>> temp(1,vector<int>(2, 0));
                temp[0][0]=people[i][1];
                temp[0][1]=people[i][1];
                myM.insert(make_pair(people[i][0],temp));
            }
            if(people[i][1]==0)
            {
                vector<int> temp(2,0);
                pq.push(make_pair(people[i][0],temp));
            }
        }
        for(auto it = myM.begin();it!=myM.end();it++)
        {
            sort(it->second.begin(),it->second.end(),greater<vector<int>>());
        }
        while(!pq.empty())
        {
            auto el = pq.top();
            pq.pop();
            result[0] = el.first;
            result[1] = el.second[1];
            auto it = myM.find(el.first);
            if(it->second.size()-1==0) myM.erase(it);
            else it->second.resize(it->second.size()-1);
            results.push_back(result);
            reduceVals(el.first);
        }
        return results;
    }
};