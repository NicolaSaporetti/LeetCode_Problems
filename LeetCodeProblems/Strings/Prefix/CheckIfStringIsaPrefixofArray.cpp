#include <vector>
using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int pos = 0;
        for(auto& w : words)
        {
            if(s.substr(pos, w.size())==w) pos+=w.size();
            else return false;
            if(pos==s.size()) return true;
        }
        return false;
    }
};