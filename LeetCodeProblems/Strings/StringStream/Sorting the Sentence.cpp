#include <map>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        map<int,string> m;
        stringstream ss (s);
        string word;
        string res;
        while (ss >> word) m[word.back()-'0']=word.substr(0,word.size()-1);
        for(auto& [key,val] : m)
        {
            res+=val;
            res+=' ';
        }
        res.pop_back();
        return res;
    }
};