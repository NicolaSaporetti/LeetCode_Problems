#include <vector>
using namespace std;

class Solution {
public:
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        vector<int> v(n);
        minR = INT_MAX;
        maxR = 0;
        for(int i=0;i<n;i++) v[i]=i+1;
        compute(v,1,firstPlayer,secondPlayer);
        return {minR,maxR};
    }
private:
    void compute(vector<int>& v, int round, int f, int s)
    {
        int sz = v.size();
        int p1 = 0;
        int p2 = 0;
        for(int i=0;i<sz;i++)
        {
            if(v[i]==f) p1 = i;
            if(v[i]==s) p2 = i;
        }
        if(p1+p2==sz-1)
        {
            minR = min(minR, round);
            maxR = max(maxR, round);
        }
        else
        {
            int match = sz/2-2;
            if(sz%2==1 &&(p1==sz/2 || p2==sz/2)) match++;
            if(match<=0) computeDeterministicSolution(v,round,f,s);
            else computeRandomSolution(v,round,f,s,match);
        }
    }
    
    void computeDeterministicSolution(vector<int>& v, int round, int f, int s)
    {
        int sz = v.size();
        vector<int> v2(sz);
        int pos = 0;
        for(int j=0;j<(sz+1)/2;j++)
        {
            if(sz%2==1 && j==sz/2) v2[j]=v[j];
            else if(v[j]==f || v[j]==s)
            {
                v2[j]=v[j];
                v2[sz-1-j]=-1;
            }
            else
            {
                v2[j]=-1;
                v2[sz-1-j]=v[sz-1-j];
            }
        }
        int p=0;
        for(int j=0;j<sz;j++) if(v2[j]!=-1) v2[p++]=v2[j];
        v2.resize(p);
        compute(v2,round+1,f,s);
    }
    
    void computeRandomSolution(vector<int>& v, int round, int f, int s, int match)
    {
        int sz = v.size();
        for(int i=0;i<(1<<match);i++)
        {
            vector<int> v2(sz);
            int pos = 0;
            for(int j=0;j<(sz+1)/2;j++)
            {
                if(sz%2==1 && j==sz/2) v2[j]=v[j];
                else if(v[j]==f || v[j]==s)
                {
                    v2[j]=v[j];
                    v2[sz-1-j]=-1;
                }
                else if(v[sz-1-j]==f || v[sz-1-j]==s)
                {
                    v2[j]=-1;
                    v2[sz-1-j]=v[sz-1-j];
                }
                else if((1<<pos) & i)
                {
                    v2[j]=v[j];
                    v2[sz-1-j]=-1;
                    pos++;
                }
                else
                {
                    v2[j]=-1;
                    v2[sz-1-j]=v[sz-1-j];
                    pos++;
                }
            }
            int p=0;
            for(int j=0;j<sz;j++) if(v2[j]!=-1) v2[p++]=v2[j];
            v2.resize(p);
            compute(v2,round+1,f,s);
        }
    }
    
    int minR;
    int maxR;
};