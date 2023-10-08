#include <vector>
using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int sz = s1.size();
        vector<vector<int>> dif(26,vector<int>(2,0));
        for(int i=0;i<sz;i++)
            if(s1[i]!=s2[i])
            {
                dif[s1[i]-'a'][i%2]++;
                dif[s2[i]-'a'][i%2]--;
            }
        for(int i=0;i<26;i++)
            for(int j=0;j<2;j++) if(dif[i][j]) return false;
        return true;
    }
};