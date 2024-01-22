#include <vector>
using namespace std;

class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if(a==e)
        {
            if(checkH(a,b,e,f,c,d)) return 2;
            else return 1;
        }
        if(b==f)
        {
            if(checkV(a,b,e,f,c,d)) return 2;
            else return 1;
        }
        for(int i=0;i<8;i++)
        {
            if(i+c==e && i+d==f)
            {
                if(checkDM(c,d,e,f,a,b)) return 2;
                else return 1;
            }
            if(e+i==c && f+i==d)
            {
                if(checkDM(e,f,c,d,a,b)) return 2;
                else return 1;
            }
            if(i+c==e && d-i==f)
            {
                if(checkDm(c,d,e,f,a,b)) return 2;
                else return 1;
            }
            if(e+i==c && f-i==d)
            {
                if(checkDm(e,f,c,d,a,b)) return 2;
                else return 1;
            }
        }
        return 2;
    }
private:
    bool checkH(int a, int b, int e, int f, int c, int d)
    {
        if(c!=a) return false;
        for(int i=min(b,f)+1;i<max(b,f);i++)
        {
            if(d==i) return true;
        }
        return false;
    }
    bool checkV(int a, int b, int e, int f, int c, int d)
    {
        if(d!=b) return false;
        for(int i=min(a,e)+1;i<max(a,e);i++)
        {
            if(c==i) return true;
        }
        return false;
    }
    bool checkDM(int a, int b, int e, int f, int c, int d)
    {
        for(int i=1;i<f-b;i++)
        {
            if(a+i==c && b+i==d) return true;
        }
        return false;
    }
    bool checkDm(int a, int b, int e, int f, int c, int d)
    {
        for(int i=1;i<e-a;i++)
        {
            if(a+i==c && b-i==d) return true;
        }
        return false;
    }
};