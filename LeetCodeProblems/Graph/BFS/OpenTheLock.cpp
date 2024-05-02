#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> vis(10000);
        for(auto e : deadends) vis[convertToInt(e)]=true;
        queue<string> q;
        if(!vis[0])q.push("0000");
        vis[0]=true;
        int r = 0;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                string el = q.front();
                q.pop();
                if(el==target) return r;
                for(int j=0;j<4;j++)
                {
                    char v = el[j];
                    el[j]=((10+(el[j]-'0')-1)%10)+'0';
                    int eln = convertToInt(el);
                    if(!vis[eln])
                    {
                        q.push(el);
                        vis[eln]=true;
                    }
                    el[j]=v;
                    el[j]=((10+(el[j]-'0')+1)%10)+'0';
                    eln = convertToInt(el);
                    if(!vis[convertToInt(el)])
                    {
                        q.push(el);
                        vis[eln]=true;
                    }
                    el[j]=v;
                }
            }
            r++;
        }
        return -1;
    }
private:
    int convertToInt(string& s)
    {
        return (s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
    }
};