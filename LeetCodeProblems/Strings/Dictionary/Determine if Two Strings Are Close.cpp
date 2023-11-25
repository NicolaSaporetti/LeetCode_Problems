#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        set<char> s1;
        set<char> s2;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(auto c : word1)
        {
            v1[c-'a']++;
            s1.insert(c);
        }
        for(auto c : word2)
        {
            v2[c-'a']++;
            s2.insert(c);
        }
        for(auto& e : s1) if(s2.find(e)==s2.end()) return false;
        sort(begin(v1),end(v1));
        sort(begin(v2),end(v2));
        for(int i=0;i<26;i++) if(v1[i]!=v2[i]) return false;
        return true;
    }
};