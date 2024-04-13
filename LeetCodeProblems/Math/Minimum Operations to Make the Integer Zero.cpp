using namespace std;

class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long long lnum1 = num1;
        for(int i=1;i<=60;i++)
        {
            lnum1-=(long long)num2;
            if(lnum1<=0) return -1;
            int bits = __builtin_popcountll(lnum1);
            if(bits<=i)
            {
                if(lnum1>=i) return i;
                else return -1;
            }
        }
        return -1;
    }
};