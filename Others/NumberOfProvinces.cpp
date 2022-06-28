#include <iostream>
#include <vector>
using namespace std;

class DisjoinSet {
public:
    DisjoinSet(int sz): root(sz), heigth(sz)
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
        for(int i = 0; i < heigth.size(); i++)
        {
            if(root[i] == i) sets++;
        }
        return sets;
    }
    
    bool are_connect(int x, int y)
    {
        return (find_root(x) == find_root(y));
    }

private:
vector<int> root;
vector<int> heigth;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int sz = isConnected.size();
        DisjoinSet set(sz);
        for(int i = 0; i < sz; i++)
        {
            for(int j = i+1; j < sz; j++)
                if(isConnected[i][j])
                {
                    set.connect(i,j);
                }
        }
        return set.get_sets();
    }
};