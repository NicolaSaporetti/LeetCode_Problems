#include <vector>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> v;
        for(int i=0;i<dominoes.size();i++)
        {
            if(dominoes[i]=='L' || dominoes[i]=='R')
            {
                v.push_back(i);
            }
        }
        int s = 0;
        for(int i=0;i<v.size();i++)
        {
            if(dominoes[v[i]]=='L')
            {
                takeDownLeft(s,v[i],dominoes);
                s = v[i]+1;
            }
            else
            {
                s = v[i];
                if(i+1<v.size())
                {
                    if(dominoes[v[i+1]]=='L')
                    {
                        takeDownRight(s,((v[i+1]-v[i]+1)/2)+v[i]-1,dominoes);
                        takeDownLeft(((v[i+1]-v[i])/2)+v[i]+1,v[i+1],dominoes);
                        s = v[i+1]+1;
                        i++;
                    }
                    else
                    {
                        takeDownRight(s,v[i+1]-1,dominoes);
                        s = v[i+1];
                    }
                }
                else
                {
                    takeDownRight(s,dominoes.size()-1,dominoes);
                    s = dominoes.size();
                }
            }
        }
        return dominoes;
    }
private:
    void takeDownLeft(int start, int end, string& dominoes)
    {
        for(int i=start;i<=end;i++)
        {
            dominoes[i]='L';
        }
    }
    void takeDownRight(int start, int end, string& dominoes)
    {
        for(int i=start;i<=end;i++)
        {
            dominoes[i]='R';
        }
    }
};