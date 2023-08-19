#include <stack>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        map<int,long long> m;
        long long res = 1;
        sz = nums.size();
        vector<int> pn = computePrime(nums);
        mod = 1e9+7;
        vector<int> l = computeLeft(pn);
        vector<int> r = computeRight(pn);
        for(int i=0;i<sz;i++)
        {
            long long val=(long long)(r[i]-i+1)*(long long)(i-l[i]+1);
            m[nums[i]] = m[nums[i]]+val;
        }
        auto it = m.rbegin();
        for(int i=0;k>0;)
        {
            long long n = min((long long)k,it->second);
            res = (res*fast_power(it->first,n))%mod;
            k-=n;
            it++;
        }
        return res;
    }
private:
    vector<int> computePrime(vector<int>& nums)
    {
        vector<int> pn(sz,0);
        for(int i=0;i<sz;i++) pn[i]=computePrimeF(nums[i]);
        return pn;
    }
    int computePrimeF(int v)
    {
        int res = 0;
        int f = 2;
        while(f*f<=v)
        {
            if(v%f==0) res++;
            while(v%f==0) v/=f;
            f++;
        }
        if(v>1) res++;
        return res;
    }
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
    long long fast_power(long long base, long long power) {
        long long result = 1;
        while(power > 0) {

            if(power % 2 == 1) { // Can also use (power & 1) to make code even faster
                result = (result*base) % mod;
            }
            base = (base * base) % mod;
            power = power / 2; // Can also use power >>= 1; to make code even faster
        }
        return result;
    }
    int sz;
    int mod;
};