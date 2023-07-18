#include <vector>
using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> v(n,0);
        vector<int> t(n,0);
        for(int i=0;i<n;i++) v[i]=i;
        bool valid = true;
        int res = 0;
        do
        {
            for(int i=0;i<n;i++)
            {
                if(i%2==0) t[i]=v[i/2];
                else t[i] = v[n/2+(i-1)/2];
            }
            for(int i=0;i<n;i++) v[i]=t[i];
            valid = true;
            res++;
            for(int i=0;i<n && valid;i++) if(v[i]!=i) valid = false;
        } while(!valid);
        return res;
    }
};