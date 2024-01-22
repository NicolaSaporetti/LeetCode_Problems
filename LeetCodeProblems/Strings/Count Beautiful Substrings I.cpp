using namespace std;

class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int res = 0;
        for(int i=0;i<s.size();i++)
        {
            int v=0;
            int c=0;
            for(int j=i;j<s.size();j++)
            {
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' ||  s[j]=='o' || s[j]=='u') v++;
                else c++;
                if(v==c && (v*c)%k==0) res++;
            }
        }
        return res;
    }
};