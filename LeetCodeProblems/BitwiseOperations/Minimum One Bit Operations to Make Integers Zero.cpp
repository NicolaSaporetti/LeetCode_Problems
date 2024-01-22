using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        int i=30;
        for(;i>=0;i--)
        {
            if((1<<i)&n)
            {
                res = (1<<(i+1))-1;
                break;
            }
        }
        int prev = 0;
        for(int j=0;j<i;j++)
        {
            if((1<<j)&n) prev = (1<<(j+1))-1-prev;
        }
        return res - prev;
    }
};