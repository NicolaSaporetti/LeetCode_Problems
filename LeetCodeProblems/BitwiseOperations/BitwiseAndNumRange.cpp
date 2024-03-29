using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int i = 1<<30;
        int result = 0;
        int maxRes = 0;
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