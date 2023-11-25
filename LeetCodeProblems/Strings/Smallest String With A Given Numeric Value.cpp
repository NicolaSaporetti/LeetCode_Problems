#include <vector>
using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        for(int i=0;i<n;i++) res.push_back('a');
        k-=n;
        for(int i=n-1;i>=0 && k>0;i--)
        {
            int val =min(k,25);
            k-=val;
            res[i]+=val;
        }
       return res;
    }
};