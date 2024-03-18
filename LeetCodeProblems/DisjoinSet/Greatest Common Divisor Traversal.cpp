#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "sieveofEratosthenes.cpp"
#include "DisjoinSetUnion.cpp"
using namespace std;

vector<int> trial_division(int n, vector<int>& primes) {
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


class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        unordered_map<int,unordered_set<int>> m;
        vector<int> pr = primes(1e5);
        for(int i=0;i<nums.size();i++)
        {
            vector<int> comp = trial_division(nums[i],pr);
            for(auto c : comp) m[c].insert(i);
        }
        DisjoinSetUnion ds(nums.size());
        for(auto [k,v] : m)
        {
            auto it = v.begin();
            int first = *it;
            it++;
            for(;it!=v.end();it++) ds.connect(first,*it);
        }
        return (ds.get_sets()==1);
    }
};