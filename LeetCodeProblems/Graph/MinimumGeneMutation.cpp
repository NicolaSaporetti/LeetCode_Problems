#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int sz=bank.size();
        vector<bool> visited(sz,false);
        queue<string> q;
        q.push(start);
        int step = 0;
        while(!q.empty())
        {
            int num = q.size();
            for(int i=0;i<num;i++)
            {
                string el = q.front();
                q.pop();
                if(el==end) return step;
                for(int j=0;j<sz;j++)
                {
                    if(!visited[j] && isDistanceOne(el,bank[j]))
                    {
                        q.push(bank[j]);
                        visited[j]=true;
                    }
                }
            }
            step++;
        }
        return -1;
    }
    
    bool isDistanceOne(string& origin, string& dest)
    {
        int res = 0;
        for(int i=0;i<origin.size();i++)
        {
            if(origin[i]!=dest[i]) res++;
        }
        return (res==1)? true : false;
    }
};