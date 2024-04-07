#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> r;
        vector<bool> v = sieveofEratosthenes(n);
        for(int i=2;i<=n/2;i++) if(v[i] && v[n-i]) r.push_back({i,n-i});
        return r;
    }
private:
    vector<bool> sieveofEratosthenes(int n)
    {
        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int j = 4; j <= n; j += 2) is_prime[j] = false;
        for (int i = 3; i * i <= n; i+=2) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        return is_prime;
    }
};