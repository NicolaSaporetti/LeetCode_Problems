#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> res;
        set<int> s1,s2;
        vector<int> v1 = rabin_karp(a,s);
        vector<int> v2 = rabin_karp(b,s);
        for(auto e : v1) s1.insert(e);
        for(auto e : v2) s2.insert(e);
        for(auto e : s1)
        {
            auto it = s2.lower_bound(e);
            auto it2 = s2.lower_bound(e-k);
            if((it!=s2.end() && abs(*it-e)<=k) || (it2!=s2.end() && abs(*it2-e)<=k)) res.push_back(e);
        }
        return res;
    }
private:
    vector<int> rabin_karp(string const& s, string const& t) {
        const int p = 31; 
        const int m = 1e9 + 9;
        int S = s.size(), T = t.size();

        vector<long long> p_pow(max(S, T)); 
        p_pow[0] = 1; 
        for (int i = 1; i < (int)p_pow.size(); i++) 
            p_pow[i] = (p_pow[i-1] * p) % m;

        vector<long long> h(T + 1, 0); 
        for (int i = 0; i < T; i++)
            h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
        long long h_s = 0; 
        for (int i = 0; i < S; i++) 
            h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

        vector<int> occurrences;
        for (int i = 0; i + S - 1 < T; i++) {
            long long cur_h = (h[i+S] + m - h[i]) % m;
            if (cur_h == h_s * p_pow[i] % m)
                occurrences.push_back(i);
        }
        return occurrences;
    }
};