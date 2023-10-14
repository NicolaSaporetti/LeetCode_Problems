using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int d1 = abs(fx-sx);
        int d2 = abs(fy-sy);
        if(sx==fx && sy==fy) return (t==0 || t>=2);
        return max(d1,d2)<=t;
    }
};