using namespace std;

class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        int val = -1;
        for(int i=1;i<=10;i++)
        {
            if((k*i)%10==num%10)
            {
                val = i;
                break;
            }
        }
        if(val!=-1 && val*k>num) val = -1;
        return val;
    }
};