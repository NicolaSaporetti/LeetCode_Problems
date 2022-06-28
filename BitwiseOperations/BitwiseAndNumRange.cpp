#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(right ==0) return 0;
        int i = 1<<30;
        int result = 0;
        int maxRes = 0;
        while(!(i&right))
        {
            i=i>>1;
        }
        while(i)
        {
            if(right&i)
            {
                maxRes +=i;
                if(left>=maxRes)
                {
                    result+=i;
                }
            }
            i=i>>1;
        }
        return result;
    }
};