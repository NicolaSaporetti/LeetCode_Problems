class DisjoinSet {
public:
    DisjoinSet(int sz): root(sz), heigth(sz), sz(sz)
    {
        for(int i = 0; i < sz; i++)
        {
            root[i] = i;
            heigth[i] = 1;
        }
    }

    int find_root(int x)
    {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find_root(root[x]);
    }

    void connect(int x, int y)
    {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x!=root_y)
        {
            if(heigth[root_x]>heigth[root_y])
            {
                root[root_y] = root_x;
                update_base_root(root_y);
            }
            else if(heigth[root_x]<heigth[root_y])
            {
                root[root_x] = root_y;
                update_base_root(root_x);
            }
            else{
                root[root_y] = root_x;
                update_base_root(root_y);
                heigth[root_x]++;
            }
        }
    }
    
    void connect_fast(int x, int y)
    {
        int root_x = find_root(x);
        int root_y = find_root(y);
        if(root_x!=root_y)
        {
            if(heigth[root_x]>heigth[root_y])
            {
                root[root_y] = root_x;
            }
            else if(heigth[root_x]<heigth[root_y])
            {
                root[root_x] = root_y;
            }
            else{
                root[root_y] = root_x;
                heigth[root_x]++;
            }
        }
    }

    int get_sets()
    {
        int sets = 0;
        for(int i = 0; i < sz; i++)
        {
            if(root[i] == i) sets++;
        }
        return sets;
    }

    bool are_connect(int x, int y)
    {
        return (find_root(x) == find_root(y));
    }
    
    set<int> get_element_with_root_x(int x)
    {
        set<int> s;
        int base = find_root(x);
        for(int i=0;i<root.size();i++) if(root[i]==base) s.insert(i);
        return s;
    }

private:
    void update_base_root(int root_to_convert)
    {
        for(int i=0;i<sz;i++) if(root[i]==root_to_convert) find_root(i);
    }
    
    vector<int> root;
    vector<int> heigth;
    int sz;
};