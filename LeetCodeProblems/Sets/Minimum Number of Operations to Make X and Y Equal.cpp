#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        q.push(x);
        s.insert(x);
        int v = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                int e = q.front();
                q.pop();
                if(e==y) return v;
                add(e+1);
                add(e-1);
                if(e%11==0) add(e/11);
                if(e%5==0) add(e/5);
            }
            v++;
        }
        return -1;
    }
private:
    void add(int v)
    {
        if(s.find(v)==s.end())
        {
            q.push(v);
            s.insert(v);
        }
    }
    
    set<int> s;
    queue<int> q;
};