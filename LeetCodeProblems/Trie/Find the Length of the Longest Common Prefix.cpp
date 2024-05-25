#include <vector>
#include "Trie.cpp"
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* t = new Trie();
        for(auto e : arr2)
        {
            vector<int> v;
            while(e>0)
            {
                v.push_back(e%10);
                e/=10;
            }
            reverse(begin(v),end(v));
            t->insert(v);
        }
        int res = 0;
        for(auto e : arr1)
        {
            vector<int> v;
            while(e>0)
            {
                v.push_back(e%10);
                e/=10;
            }
            reverse(begin(v),end(v));
            int r = t->search(v);
            res = max(res,r);
        }
        return res;
    }
};