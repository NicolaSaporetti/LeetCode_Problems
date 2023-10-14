#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int sz = edges.size();
        r.assign(sz,-1);
        for(int i=0;i<sz;i++)
        {
            if(r[i]!=-1) continue;
            stack<int> st;
            unordered_map<int,int> m;
            int j=0;
            int cur = i;
            do
            {
                st.push(cur);
                m[cur]=j++;
                cur = edges[cur];
            }
            while(m.count(cur)==0 && r[cur]==-1);
            if(m.count(cur)>0) manageLoop(st,m,j,cur);
            while(!st.empty())
            {
                r[st.top()]=r[cur]+1;
                cur = st.top();
                st.pop();
            }
        }
        return r;
    }
private:
    void manageLoop(stack<int>& st, unordered_map<int,int>& m, int j, int cur)
    {
        int d = j-m[cur];
        int e;
        do
        {
            e = st.top();
            st.pop();
            r[e]=d;
        }
        while(e!=cur);
    }
    
    vector<int> r;
};