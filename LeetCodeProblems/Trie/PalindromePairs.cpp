#include <vector>
#include "Trie.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& A) {
        vector<vector<int>> res;
        Trie trie;
        for(int i=0;i<A.size();i++) trie.insert(A[i],i);
        for(int i=0;i<A.size();i++) trie.search(A[i],i,res);
        return res;
    }
};