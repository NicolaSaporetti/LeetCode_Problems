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