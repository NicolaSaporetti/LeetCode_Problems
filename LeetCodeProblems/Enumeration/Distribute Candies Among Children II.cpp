using namespace std;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long tot = 0;
        for(int i=0;i<=min(n,limit);i++)
        {
            long long leftC = n-i;
            if(leftC>2*limit) continue;
            else if(leftC<=limit) tot+=(long long)(leftC+1);
            else tot+=(long long)(2*limit+1-leftC);
        }
        return tot;
    }
};