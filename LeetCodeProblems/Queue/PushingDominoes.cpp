#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        queue<int> q;
        for(int i=0;i<dominoes.size();i++) if(dominoes[i]=='L' || dominoes[i]=='R') q.push(i);
        int s = 0;
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            if(dominoes[el]=='L')
            {
                takeDownLeft(s,el,dominoes);
                s = el+1;
            }
            else
            {
                if(!q.empty())
                {
                    if(dominoes[q.front()]=='L')
                    {
                        int last_el = q.front();
                        int dist = last_el-el-1;
                        q.pop();
                        takeDownRight(el,el+dist/2,dominoes);
                        takeDownLeft(last_el-dist/2,last_el,dominoes);
                        s = last_el+1;
                    }
                    else
                    {
                        takeDownRight(el,q.front()-1,dominoes);
                        s = q.front();
                    }
                }
                else
                {
                    takeDownRight(el,dominoes.size()-1,dominoes);
                }
            }
        }
        return dominoes;
    }
private:
    void takeDownLeft(int start, int end, string& dominoes)
    {
        for(int i=start;i<=end;i++) dominoes[i]='L';
    }
    void takeDownRight(int start, int end, string& dominoes)
    {
        for(int i=start;i<=end;i++) dominoes[i]='R';
    }
};