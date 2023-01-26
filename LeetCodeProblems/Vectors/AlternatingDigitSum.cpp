using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        int tot = 0;
        int i=0;
        for(;n>0;i++)
        {
            if(i%2==0) tot+=n%10;
            else tot-=n%10;
            n/=10;
        }
        return (i%2==1)? tot : -tot;
    }
};