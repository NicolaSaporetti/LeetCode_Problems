#include <vector>
using namespace std;

class FenwickTreeOneBasedIndexing
{
public:
    FenwickTreeOneBasedIndexing(int maxNum): BIT(maxNum+1), sz(maxNum+1) {}
    FenwickTreeOneBasedIndexing(vector<int>& v)
    {
        sz = *max_element(begin(v),end(v))+1;
        BIT.assign(sz,0);
        for (size_t i = 0; i < sz; i++) sum(i, v[i]);
    }
    
    void add(int idx, int delta) {
        for (; idx < sz; idx += idx & -idx)
            BIT[idx] += delta;
    }
    
    int sum(int idx){
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx)
            ans += BIT[idx];
        return ans;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
private: 
    vector<int> BIT;
    int sz;
};