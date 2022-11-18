#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string,int> m;
        vector<string> solutions;
        for(int i=9;i<s.size();i++) m[s.substr(i-9,10)]++;
        for(auto e : m) if(e.second>1) solutions.push_back(e.first);
        return solutions;
    }
};