#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res;
        string temp;
        map<string,string> m;
        for(auto& e : knowledge) m[e[0]]=e[1];
        bool open = false;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(') open = true;
            else if(s[i]==')')
            {
                open = false;
                auto it = m.find(temp);
                if(it==m.end()) res.push_back('?');
                else res+=it->second;
                temp = "";
            }
            else
            {
                if(open) temp+=s[i];
                else res+=s[i];
            }
        }
        return res;
    }
};