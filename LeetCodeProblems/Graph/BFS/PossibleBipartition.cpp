#include <vector>
#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        m.resize(n);
        set<int> sA;
        set<int> sB;
        visited.assign(n,false);

        for(auto e : dislikes)
        {
            m[e[0]-1].insert(e[1]-1);
            m[e[1]-1].insert(e[0]-1);
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bool isFirstSet = true;
                sA.insert(i);
                q.push(i);
                while(!q.empty())
                {
                    int num = q.size();
                    for(int j=0;j<num;j++)
                    {
                        bool conflictRaised = (isFirstSet)? computeElement(sA,sB) : computeElement(sB,sA);
                        if(!conflictRaised) return false;
                    }
                    isFirstSet = !isFirstSet;
                }
            }
        }
        return true;
    }
private:
    bool computeElement(set<int>& start, set<int>& dest)
    {
        int el = q.front();
        q.pop();
        start.insert(el);
        for(auto e : m[el])
        {
            if(start.find(e)!=start.end()) return false;
            if(!visited[e])
            {
                dest.insert(e);
                visited[e]=true;
                q.push(e);
            }
        }
        return true;
    }

    queue<int> q;
    vector<int> visited;
    vector<set<int>> m;
};