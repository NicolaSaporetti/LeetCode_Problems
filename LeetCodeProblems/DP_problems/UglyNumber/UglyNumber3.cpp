using namespace std;

class Solution {
public:
    #define ll long long
    int nthUglyNumber(int n, int a, int b, int c) {
        ll l = min(a,min(b,c));
        ll h = INT_MAX;
        ll result = l;
        while(l<=h)
        {
            ll  mid = l + (h-l)/2;
            if(check(mid,a,b,c)<n)
            {
                l = mid+1;
            }
            else
            {
                result = mid;
                h = mid-1;
            }
        }
        return result;
    }
private:
    ll lcm(ll a, ll b)
    {
        return a*b/__gcd(a, b);
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
};