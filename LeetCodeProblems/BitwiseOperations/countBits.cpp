#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++) res.push_back(count_1_digits(i));
        return res;
    }
private:
    int count_1_digits(int num)
    {
        int res = 0;
        while(num>0)
        {
            if(num%2==1) res++;
            num>>=1;
        }
        return res;
    }
};