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