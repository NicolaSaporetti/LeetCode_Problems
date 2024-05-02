#include <vector>

class DisjoinSetUnion {
public:
    DisjoinSetUnion(int sz): parent(sz), rank(sz), sz(sz)
    {
        for(int i = 0; i < sz; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void connect(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    bool are_connect(int x, int y)
    {
        return (find_set(x) == find_set(y));
    }

    int get_set_num()
    {
        int sets = 0;
        for(int i = 0; i < sz; i++)
            if(parent[i] == i) sets++;
        return sets;
    }
    map<int,vector<int>> get_sets()
    {
        map<int,vector<int>> r;
        for(int i = 0; i < sz; i++) r[find_set(i)].push_back(i);
        return r;
    }
    vector<int> parent;
    vector<int> rank;
    int sz;
};