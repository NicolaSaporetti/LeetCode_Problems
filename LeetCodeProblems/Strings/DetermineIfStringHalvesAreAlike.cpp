using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        int v1= calculateVowel(0,s.size()/2-1,s);
        int v2 = calculateVowel(s.size()/2,s.size()-1,s);
        return (v1==v2)? true : false;
    }
    
private:
    int calculateVowel(int l, int r, string& s)
    {
        int tot = 0;
        for(int i=l;i<=r;i++) if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ||
                                 s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U') tot++;
        return tot;
    }
};