using namespace std;

class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        long long sum = 0;
        int mod = 1e9+7;
        long long num = min(target/2,n);
        long long rest = n-num;
        sum+=num*(num+1)/2;
        if(n>0) sum+=rest*(rest+1)/2+((long long)target-1)*rest;
        return sum%mod;
    }
};