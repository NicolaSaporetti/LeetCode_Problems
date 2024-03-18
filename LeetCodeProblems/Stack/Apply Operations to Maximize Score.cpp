#include <stack>
#include <map>
#include <vector>
using namespace std;

vector<int> sieveofEratosthenes(int n)
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

vector<int> trial_division_unique(int n, vector<int>& primes) {
    vector<int> factorization;
    for (int d : primes) {
        if (d * d > n)
            break;
        if(n%d==0) factorization.push_back(d);
        while (n % d == 0) n /= d;
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

long long binpowWithModulo(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        sz = nums.size();
        vector<int> v1 = nums;
        vector<int> primes = sieveofEratosthenes(1e5);
        for(auto&e : nums) e = trial_division_unique(e,primes).size();
        vector<int> l = computeLeft(nums);
        vector<int> r = computeRight(nums);
        map<int,long long> m;
        for(int i=0;i<sz;i++)
        {
            m[v1[i]]+=((long long)(i-l[i]+1)*(long long)(r[i]-i+1));
        }
        int mod = 1e9+7;
        long long res = 1;
        for(auto it = m.rbegin();it!=m.rend();it++)
        {
            int val = min((long long)k,it->second);
            k-=val;
            res = (res*binpowWithModulo(it->first,val,mod))%mod;
            if(k==0) break;
        }
        return res;
    }
private:
    vector<int> computeLeft(vector<int>& pn)
    {
        vector<int> v(sz,0);
        stack<int> st;
        for(int i=0;i<sz;i++)
        {
            while(!st.empty() && pn[st.top()]<pn[i]) st.pop();
            if(st.empty()) v[i]=0;
            else v[i]=st.top()+1;
            st.push(i);
        }
        return v;
    }
    vector<int> computeRight(vector<int>& pn)
    {
        vector<int> v(sz,0);
        stack<int> st;
        for(int i=sz-1;i>=0;i--)
        {
            while(!st.empty() && pn[st.top()]<=pn[i]) st.pop();
            if(st.empty()) v[i]=sz-1;
            else v[i]=st.top()-1;
            st.push(i);
        }
        return v;
    }

    int sz;
};