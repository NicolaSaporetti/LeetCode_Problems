using namespace std;

class Solution {
public:
    #define ll long long
    ll gcd(ll a, ll b)
    {
        if (b == 0)
        return a;
        return gcd(b, a % b);
    }
    
    ll lcm(ll a, ll b)
    {
        return (a / gcd(a, b)) * b;
    }
    
    ll check(ll mid , int a , int b , int c)
    {
        ll j1 = lcm(a,b);
        ll j2 = lcm(a,c);
        ll j3 = lcm(b,c);
        ll j4 = lcm(j1,c);
        ll k = mid/a + mid/b + mid/c + mid/j4 - (mid/j1 + mid/j2 + mid/j3);
        return k;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l = min(a,min(b,c));
        ll h = INT_MAX;
        while(l<h)
        {
            ll  mid = l + (h-l)/2;
            if(check(mid,a,b,c)<n) l = mid+1;
            else h = mid;
        }
        return l;
    }
};