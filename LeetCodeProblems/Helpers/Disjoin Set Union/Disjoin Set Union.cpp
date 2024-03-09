#include <vector>

class DisjoinSetUnion {
public:
    DisjoinSetUnion(int sz): parent(sz), heigth(sz), sz(sz)
    {
        for(int i = 0; i < sz; i++)
        {
            parent[i] = i;
            parent[i] = 0;
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

    int get_sets()
    {
        int sets = 0;
        for(int i = 0; i < sz; i++)
            if(root[i] == i) sets++;
        return sets;
    }
    
    vector<int> get_element_with_root_x(int x)
    {
        vector<int> v;
        int base = find_set(x);
        for(int i=0;i<sz;i++) if(root[i]==base) v.push_back(i);
        return v;
    }

    vector<int> parent;
    vector<int> heigth;
    int sz;
};