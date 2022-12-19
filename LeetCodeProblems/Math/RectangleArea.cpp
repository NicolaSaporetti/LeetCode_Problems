using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int bcx=max(ax1,bx1);
        int bcy=max(ay1,by1);
        int tcx=min(ax2,bx2);
        int tcy=min(ay2,by2);
        int area = (tcx-bcx<0 || tcy-bcy<0)? 0 : (tcx-bcx)*(tcy-bcy);
        return (ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1)-area;
    }
};