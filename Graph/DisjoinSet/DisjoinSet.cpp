#include "DisjoinSet.hpp"

DisjoinSet::DisjoinSet(int sz): root(sz), heigth(sz)
{
    for(int i = 0; i < sz; i++)
    {
        root[i] = i;
        heigth[i] = 1;
    }
}

int DisjoinSet::find_root(int x)
{
    if (x == root[x]) {
        return x;
    }
    return root[x] = find_root(root[x]);
}

void DisjoinSet::connect(int x, int y)
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

int DisjoinSet::get_sets()
{
    int sets = 0;
    for(int i = 0; i < heigth.size(); i++)
    {
        if(root[i] == i) sets++;
    }
    return sets;
}

bool DisjoinSet::are_connect(int x, int y)
{
    return (find_root(x) == find_root(y));
}