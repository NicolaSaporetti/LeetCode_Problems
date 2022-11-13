#include <set>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        for(int i=1;i<=n;i++) numbers.insert(i);
        k = k-1;
        int fac = factorial(n);
        for(int i=n;i>0;i--)
        {
            int j = 0;
            fac/=i;
            int order = k/fac;
            k = k%fac;
            for(auto it=numbers.begin();it!=numbers.end();it++)
            {
                if(j==order)
                {
                    s.push_back(*it+48);
                    numbers.erase(it);
                    break;
                }
                j++;
            }
        }
        return s;
    }
private:
    int factorial(int v)
    {
        int res = 1;
        for(int i=v;i>1;i--) res*=i;
        return res;
    }
    
    set<int> numbers;
};