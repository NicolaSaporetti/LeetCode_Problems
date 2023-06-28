class Solution {
public:
    int longestString(int x, int y, int z) {
        int rep = min(x,y);
        int res=z+rep*2;
        x-=rep;
        y-=rep;
        if(x>0 || y>0) res++;
        return res*2;
    }
};