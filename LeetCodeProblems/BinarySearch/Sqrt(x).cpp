using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int s=0, e = INT_MAX;
        int ans=0;
        while(s<=e)
        {
            long mid=(s+e)/2;
            if(mid*mid<=x) 
            {
                ans = mid;
                s = mid+1;
            }
            else
            {
                 e = mid-1;
            }
        }
        return ans;
    }
};