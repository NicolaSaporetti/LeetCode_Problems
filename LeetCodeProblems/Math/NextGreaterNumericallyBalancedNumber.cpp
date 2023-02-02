#include <vector>
using namespace std;

class Solution {
public:
    int nextBeautifulNumber(int n) {
        while(!isBalanced(++n));
        return n;
    }
private:
    bool isBalanced(int n)
    {
        vector<int> v(10,0);
        while(n>0)
        {
            v[n%10]++;
            n/=10;
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0 && v[i]!=i) return false;
        }
        return true;
    }
};