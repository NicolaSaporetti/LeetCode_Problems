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

long long inverseMod(long long val)
{
    int mod = 1e9+7;
    return binpowWithModulo(factN, mod - 2, mod);
}