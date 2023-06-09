using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        for(int i=0;i<32;i++)
        {
            bool cb =((1<<i) & c);
            bool bb =((1<<i) & b);
            bool ab =((1<<i) & a);
            if(cb && (!bb && !ab)) res++;
            if(!cb)
            {
                if(ab) res++;
                if(bb) res++;
            }
        }
        return res;
    }
};