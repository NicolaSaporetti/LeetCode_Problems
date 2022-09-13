#include <vector>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        for(int i=sqrt(num)-1;i<=sqrt(num);i++)
        {
            if(i*i==num) return true;
        }
        return false;
    }
};