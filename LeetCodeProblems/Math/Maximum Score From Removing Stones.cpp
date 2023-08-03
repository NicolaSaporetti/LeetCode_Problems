using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int notE = (a>0)+(b>0)+(c>0);
        int r = 0;
        while(notE>1)
        {
            if(c<=a && c<=b)
            {
                a--;
                b--;
                r++;
            }
            else if(a<=b && a<=c)
            {
                b--;
                c--;
                r++;
            }
            else
            {
                a--;
                c--;
                r++;
            }
            notE = (a>0)+(b>0)+(c>0);
        }
        return r;
    }
};