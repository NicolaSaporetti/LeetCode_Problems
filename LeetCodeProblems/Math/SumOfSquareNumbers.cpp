using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=sqrt(c);i>=0;i--)
        {
            int leftC = c-i*i;
            int j = sqrt(leftC);
            if(j*j==leftC) return true;
        }
        return false;
    }
};