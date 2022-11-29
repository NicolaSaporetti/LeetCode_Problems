using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int sol = 1;
        int l = 1;
        int r = n;
        while (l<=r)
        {
            int index=l+(r-l)/2;
            if(isBadVersion(index))
            {
                sol = index;
                r=index-1;
            }
            else l=index+1;
        } 
        return sol;
    }
};