#include <iostream>
#include <set>
using namespace std;

class Solution {
private:
    set<int> numbers;
    
    void setUpNumbersSet(int n)
    {
        for(int i=1;i<=n;i++)
        {
            numbers.insert(i);
        }
    }
    int factorial(int v)
    {
        int res = 1;
        for(int i=v;i>1;i--)
        {
            res*=i;
        }
        return res;
    }
public:
    string getPermutation(int n, int k) {
        string s;
        setUpNumbersSet(n);
        k = k-1;
        int fac = factorial(n);
        for(int i=n;i>1;i--)
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
        s.push_back(*numbers.begin()+48);
        return s;
    }
};