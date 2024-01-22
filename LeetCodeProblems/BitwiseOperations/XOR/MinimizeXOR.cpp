using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int tot = 0;
        int value = 0;
        while(num2>0)
        {
            if(num2%2==1) tot++;
            num2/=2;
        }
        for(int i=30;i>=0 && tot>0;i--)
        {
            if(num1&(1<<i))
            {
                value|=(1<<i);
                tot--;
            }
        }
        for(int i=0;i<31 && tot>0;i++)
        {
            if((num1&(1<<i))==0)
            {
                value|=(1<<i);
                tot--;
            }
        }
        return value;
    }
};