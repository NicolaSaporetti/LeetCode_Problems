using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int pos=0;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9')) s[pos++] = s[i];
            else if(s[i]>='A' && s[i]<='Z') s[pos++] = s[i]-'A'+'a';
        }
        s.resize(pos);
        for(int i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()-1-i]) return false;
        return true;
    }
};