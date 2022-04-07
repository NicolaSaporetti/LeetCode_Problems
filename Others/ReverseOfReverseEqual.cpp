#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
private:
    int reverse(int num)
    {
        int result = 0;
        while (num>0)
        {
            result*=10;
            result+=num%10;
            num/=10;
        }
        return result;
    }
public:
    bool isSameAfterReversals(int num) {
        int reverse1 = reverse(num);
        int reverse2 = reverse(reverse1);
        if(reverse2==num) return true;
        else return false;
    }
};

int main()
{
    Solution solution;
    cout<<solution.reverseBits(123)<<endl;
    return 0;
}