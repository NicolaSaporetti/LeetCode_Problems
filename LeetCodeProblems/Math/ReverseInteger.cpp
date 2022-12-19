using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long int solution = 0;
        for(int i=0; abs(x)>0; i++)
        {
            solution*= 10;
            solution+= x%10;
            x/=10;
        }
        if(solution > INT_MAX || solution < INT_MIN) solution = 0;
        return static_cast<int>(solution);
    }
};