#include <vector>
using namespace std;

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int min = 1;
        int max = *max_element(begin(q),end(q));
        int res = min;
        while(min<=max)
        {
            int med = min+(max-min)/2;
            if(canObtain(med,q,n))
            {
                res = med;
                max = med-1;
            }
            else min = med+1;
        }
        return res;
    }
private:
    bool canObtain(int val, vector<int>& q, int n)
    {
        for(auto& e : q)
        {
            int numS = 1;
            if(e>val)
            {
                numS=e/val+((e%val==0)? 0 : 1);
            }
            n-=numS;
            if(n<0) return false;
        }
        return true;
    }
};