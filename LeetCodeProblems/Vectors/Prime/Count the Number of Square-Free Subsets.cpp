#include <vector>
using namespace std;

class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        v.assign(31,0);
        res = 0;
        mod = 1e9+7;
        for(auto e : nums) v[e]++;
        for(int i=2;i<=30;i++) if(v[i]>0) mask(i); 
        compute(0,0,1);
        long long p1 = pow1(v[1]);
        return (res*p1+p1-1)%mod;
    }
private:
    void compute(int start, int mask, long long tres)
    {
        for(int i=start;i<simple.size();i++)
        {
            if((mask&simple[i].first)==0)
            {
                int newMask = mask|simple[i].first;
                long long nres = tres*v[simple[i].second];
                res=(res+nres)%mod;
                compute(i+1,newMask,nres%mod);
            }
        }
    }
    void mask(int num)
    {
        vector<int> p = trial_division(num);
        int r = 0;
        for(auto e : p)
        {
            if(r&(1<<e)) return;
            else r|=(1<<e);
        }
        simple.push_back({r,num});
    }

    vector<int> primes(int n)
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
        vector<int> res;
        for(int i=2;i<=n;i++) if(is_prime[i]) res.push_back(i);
        return res;
    }

    vector<int> trial_division(int n) {
        vector<int> prime = primes(n);
        vector<int> factorization;
        for (int d : prime) {
            if (d * d > n)
                break;
            while (n % d == 0) {
                factorization.push_back(d);
                n /= d;
            }
        }
        if (n > 1)
            factorization.push_back(n);
        return factorization;
    }

    int pow1(int n)
    {
        int r = 1;
        for(int i=0;i<n;i++) r = (r*2)%mod;
        return r;
    }

    vector<pair<int,int>> simple;
    vector<long long> v;
    long long res;
    int mod;
};