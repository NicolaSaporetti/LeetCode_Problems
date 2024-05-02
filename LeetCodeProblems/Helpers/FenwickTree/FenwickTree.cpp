#include <vector>
using namespace std;

struct FenwickTree {
public:

    FenwickTree(int maxNum) : sz(maxNum+1), bit(maxNum+1) {}
    FenwickTree(vector<int> const &v)
    {
        sz = *max_element(begin(v),end(v))+1;
        bit.assign(sz,0);
        for (int i = 0; i < sz; i++) {
            bit[i] += v[i];
            int r = i | (i + 1);
            if (r < sz) bit[r] += bit[i];
        }
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < sz; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
private:
    vector<int> bit;
    int sz;
};