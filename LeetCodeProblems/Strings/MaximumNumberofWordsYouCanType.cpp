#include <vector>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26,false);
        for(auto& e : brokenLetters) broken[e-'a']=true;
        stringstream ss (text);
        string word;
        int res = 0;
        while (ss >> word)
        {
            bool valid = true;
            for(auto& c : word)
            {
                if(broken[c-'a']) valid = false;
            }
            if(valid) res++;
        }
        return res;
    }
};