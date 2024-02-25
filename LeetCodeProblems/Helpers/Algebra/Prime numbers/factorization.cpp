//This is the sieve
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

vector<int> trial_division(int n) {
    vector<int> primes = primes(n);
    vector<int> factorization;
    for (int d : primes) {
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