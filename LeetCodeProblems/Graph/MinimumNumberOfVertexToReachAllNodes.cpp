#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
private:
    set<int> myS;
    vector<int> res;
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        for(int i=0;i<n;i++)
        {
            myS.insert(i);
        }
        for(int i=0;i<edges.size();i++)
        {
            myS.erase(edges[i][1]);
        }
        for(auto it=myS.begin();it!=myS.end();it++)
        {
            res.push_back(*it);
        }
        return res;
    }
};