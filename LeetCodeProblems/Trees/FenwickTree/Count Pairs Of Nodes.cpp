#include <vector>
#include "..\DD\Fenwick.cpp"
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

class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> res(queries.size(),0);
        vector<vector<int>> out(n);
        vector<vector<int>> in(n);
        vector<int> incidents(n,0);
        for(auto& e : edges)
        {
            out[e[0]-1].push_back(e[1]-1);
            in[e[1]-1].push_back(e[0]-1);
        }
        for(int i=0;i<n;i++) incidents[i]+=in[i].size();
        for(int i=0;i<n;i++) incidents[i]+=out[i].size();
        int maxE = max(*max_element(begin(queries),end(queries)),*max_element(begin(incidents),end(incidents)));
        FenwickTree ft(maxE);
        for(auto& e : incidents) ft.add(e,1);
        for(int i=0;i<n-1;i++)
        {
            ft.add(incidents[i],-1);
            for(auto& e : in[i])
            {
                if(e>i)
                {
                    ft.add(incidents[e],-1);
                    incidents[e]--;
                    ft.add(incidents[e],1);
                }
            }
            for(auto& e : out[i])
            {
                if(e>i)
                {
                    ft.add(incidents[e],-1);
                    incidents[e]--;
                    ft.add(incidents[e],1);
                }
            }
            for(int j=0;j<queries.size();j++)
            {
                int dif = 1+queries[j]-incidents[i];
                if(dif<=0) res[j]+=(n-1-i);
                else
                {
                    res[j]+=ft.sum(dif,maxE);
                }
            }
            
            for(auto& e : in[i])
            {
                if(e>i)
                {
                    ft.add(incidents[e],-1);
                    incidents[e]++;
                    ft.add(incidents[e],1);
                }
            }
            for(auto& e : out[i])
            {
                if(e>i)
                {
                    ft.add(incidents[e],-1);
                    incidents[e]++;
                    ft.add(incidents[e],1);
                }
            }
        }
        return res;
    }
};