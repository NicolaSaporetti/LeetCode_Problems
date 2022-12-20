using namespace std;

class Solution {
public:
    int guessNumber(int n) {
        int l = 1;
        int pick = l;
        int r = n;
        do
        {
            int mid=l+(r-l)/2;
            int res = guess(mid);
            if(!res)
            {
                pick = mid;
                break;
            }
            else if(res==1) l=mid+1;
            else r=mid-1;
        } while (l<=r);
        return pick;
    }
};