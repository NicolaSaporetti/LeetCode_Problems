#include <vector>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        v.assign(right+1,false);
        vector<int> res(2,-1);
        int dis = INT_MAX;
        fillPrime(right);
        
        auto it = find(begin(v)+left,end(v),0);
        if(it==end(v)) return res;
        else
        {
            auto it2 = find(it+1,end(v),0);
            while(it2!=end(v))
            {
                if(it2-it<dis)
                {
                    res[0]=it-begin(v);
                    res[1]=it2-begin(v);
                    dis = it2-it;
                }
                it = it2;
                it2 = find(it+1,end(v),0);
            }
        }
        return res;
    }
private:
    void fillPrime(int right)
    {
        v[0]=true;
        v[1]=true;
        for(int i=4;i<=right;i+=2) v[i]=true;
        for(int i=3;i*i<=right;i+=2)
        {
            for(int j=i*2;j<=right;j+=i) v[j]=true;
        }
    }
    
    vector<bool> v;
};