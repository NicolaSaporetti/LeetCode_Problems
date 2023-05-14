using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                int num = i*i+j*j;
                int z = sqrt(num);
                if(z*z==num && z<=n) res++;
            }
        }
        return res;
    }
};