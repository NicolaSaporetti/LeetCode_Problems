#include <vector>
using namespace std;

class DisjoinSet {
public:
    DisjoinSet(int sz): root(sz)
    {
        for(int i = 0; i < sz; i++) root[i] = i;
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
            if(root_x<root_y)
            {
                root[root_y] = root_x;
            }
            else
            {
                root[root_x] = root_y;
            }
        }
    }

    int get_sets()
    {
        int sets = 0;
        for(int i = 0; i < root.size(); i++)
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
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjoinSet ds(26);
        vector<int> v(26,0);
        for(int i=0;i<26;i++) v[i]=i;
        for(int i=0;i<s1.size();i++) ds.connect(s1[i]-'a',s2[i]-'a');
        for(int i=0;i<s1.size();i++)
        {
            v[s1[i]-'a']=ds.find_root(s1[i]-'a');
            v[s2[i]-'a']=ds.find_root(s2[i]-'a');
        }
        for(int i=0;i<baseStr.size();i++) baseStr[i]=v[baseStr[i]-'a']+'a';
        return baseStr;
    }
};