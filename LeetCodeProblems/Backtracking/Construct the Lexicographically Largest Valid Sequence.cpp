#include <vector>
using namespace std;

class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        sz = (n-1)*2+1;
        v.assign(sz,-1);
        ava.assign(n,true);
        compute(0,n);
        return res;
    }
private:
    void compute(int pos, int n)
    {
        if(res.empty())
        {
            if(pos>=sz) res = v;
            else
            {
                if(v[pos]!=-1) compute(pos+1,n);
                else
                {
                    for(int i=n;i>=2;i--)
                    {
                        if(ava[i-1]==true && pos+i<sz && v[pos+i]==-1)
                        {
                            ava[i-1]=false;
                            v[pos]=i;
                            v[pos+i]=i;
                            compute(pos+1,n);
                            v[pos+i]=-1;
                            v[pos]=-1;
                            ava[i-1]=true;
                        }
                    }
                    if(ava[0]==true)
                    {
                        ava[0]=false;
                        v[pos]=1;
                        compute(pos+1,n);
                        v[pos]=-1;
                        ava[0]=true;
                    }
                }
            }
        }
    }
    
    vector<int> v;
    vector<int> ava;
    vector<int> res;
    int sz;
};