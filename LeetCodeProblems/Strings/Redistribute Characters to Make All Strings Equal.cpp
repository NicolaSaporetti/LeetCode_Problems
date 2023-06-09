#include <vector>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int sz = words.size();
        vector<int> occ(26,0);
        for(auto& word : words)
            for(auto& c : word) occ[c-'a']++;
        for(int i=0;i<26;i++)
        {
            if(occ[i]%sz!=0) return false;
        }
        return true;
    }
};