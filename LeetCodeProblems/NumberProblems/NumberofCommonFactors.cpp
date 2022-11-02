using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int tot=0;
        for(int i=1;i<=min(a,b);i++)
        {
            if(a%i==0 && b%i==0) tot++;
        }
        return tot;
    }
};