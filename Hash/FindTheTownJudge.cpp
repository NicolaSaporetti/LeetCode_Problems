#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
private:
    map<int,int> Mtrust;
    map<int,int> MisTrusted;
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0 && n==1) return 1;
        for(int i=0;i<trust.size();i++)
        {
            auto it = MisTrusted.find(trust[i][1]);
            if(it!=MisTrusted.end())
            {
                it->second++;
            }
            else MisTrusted.insert(make_pair(trust[i][1],1));
            auto it2 = Mtrust.find(trust[i][0]);
            if(it2!=Mtrust.end())
            {
                it2->second++;
            }
            else Mtrust.insert(make_pair(trust[i][0],1));
        }
        for(auto it=MisTrusted.begin();it!=MisTrusted.end();it++)
        {
            if(it->second==n-1 && Mtrust.find(it->first)==Mtrust.end())
            {
                return it->first;
            }
        }
        return -1;
    }
};