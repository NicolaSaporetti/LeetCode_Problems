#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> countVisitedNodes(vector<int>& edges) {
        int sz = edges.size();
        vector<int> n(sz,-1);
        for(int i=0;i<sz;i++)
        {
            int num=0;
            int current = i;
            unordered_map<int,int> m;
            stack<int> st;
            while(n[current]==-1 && m.count(current)==0)
            {
                m[current]=num++;
                st.push(current);
                current = edges[current];
            }
            if(m.count(current)>0)
            {
                int el = current;
                while(st.top()!=el)
                {
                    n[st.top()]=num-m[el];
                    st.pop();
                }
                n[st.top()]=num-m[el];
                st.pop();
            }
            while(!st.empty())
            {
                n[st.top()] = n[edges[st.top()]]+1;
                st.pop();
            }
        }
        return n;
    }
};