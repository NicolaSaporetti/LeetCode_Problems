#include <vector>
using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        vector<int> v(58,0);
        for(int i=0;i<s.size();i++)
        {
            v[s[i]-'A']++;
        }
        for(int i=25;i>=0;i--)
        {
            if(v[i]>0 && v[i+32]>0)
            {
                char a= 'A'+i;
                string r={a};
                return r;
            }
        }
        return "";
    }
};