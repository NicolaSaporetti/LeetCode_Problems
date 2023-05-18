using namespace std;

class Solution {
public:
    int countHousePlacements(int n) {
        long long start = 1;
        long long  prev = 1;
        long long res = 0;
        int mod = 1000000007;
        for(int i=0;i<n;i++)
        {
            long long temp = start;
            start=(start+prev)%mod;
            prev = temp;
            
        }
        return (start*start)%mod;
    }
};