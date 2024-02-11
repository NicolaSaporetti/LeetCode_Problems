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
    int numberOfSequence(int n, vector<int>& sick) {
        n-=sick.size();
        mod = 1e9+7;
        vector<long long> pow2 = computePow2(n);
        vector<long long> fact = computeFact(n);
        vector<long long> Invfact = computeInvFact(n, fact.back());
        int r = fact[n];
        if(sick.size()>0 && sick[0]!=0) r = (r*Invfact[sick[0]])%mod;
        if(sick.size()>0 && sick.back()!=n+sick.size()-1) r = (r*Invfact[n+sick.size()-sick.back()-1])%mod;
        for(int i=0;i<sick.size()-1;i++)
        {
            int d = sick[i+1]-sick[i]-1;
            r = (r*Invfact[d])%mod;
            r = (r*pow2[d])%mod;
        }
        return r;
    }
private:
    vector<long long> computePow2(int n)
    {
        vector<long long> v(n+1);
        v[0]=1;
        v[1]=1;
        for(int i=2;i<=n;i++) v[i]=v[i-1]*2%mod;
        return v;
    }
    vector<long long> computeFact(int n)
    {
        vector<long long> fact(n+1);
        fact[0]=1;
        fact[1]=1;
        for(int i=2;i<=n;i++) fact[i]=fact[i-1]*i%mod;
        return fact;
    }
    vector<long long> computeInvFact(int n, long long factN)
    {
        vector<long long> inv_fact(n+1);
        inv_fact[n] = binpowWithModulo(factN, mod - 2, mod);
        for(int i=n-1;i>=0;i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
        return inv_fact;
    }

    int mod;
};