#include <unordered_map>
using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        int pos = 0;
        unordered_map<char,char> cypher;
        cypher[' '] = ' ';
        for(auto i : key)
        {
            if(cypher.find(i)==cypher.end())
            {
                cypher[i]='a'+pos++;
            }
        }
        string res;
        for(auto i : message) res.push_back(cypher[i]);
        return res;
    }
};