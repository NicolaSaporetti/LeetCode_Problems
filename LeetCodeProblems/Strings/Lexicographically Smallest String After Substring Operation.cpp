using namespace std;

class Solution {
public:
    string smallestString(string s) {
        int i = 0;
        for(;i<s.size();i++) if(s[i]!='a') break;
        if(i==s.size()) s.back()=(s.back()=='a')? 'z' : s.back()-1;
        else
        {
            int j=i;
            for(;j<s.size();j++) if(s[j]=='a') break;
            for(int k=i;k<j;k++) s[k]--;
        }
        return s;
    }
};