using namespace std;

class Solution {
public:
    int minOperations(int k) {
        int res = INT_MAX;
        for(int i=1;i<=k;i++)
        {
            int hp = k/i+((k%i==0)? 0 : 1);
            res = min(res,(i-1)+(hp-1));
        }
        return res;
    }
};