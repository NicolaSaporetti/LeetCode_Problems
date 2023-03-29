#include <vector>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2,0);
        bool isOdd = true;
        while(n>0)
        {
            if(n%2==1)
            {
                if(isOdd) res[0]++;
                else res[1]++;
            }
            isOdd=!isOdd;
            n>>=1;
        }
        return res;
    }
};