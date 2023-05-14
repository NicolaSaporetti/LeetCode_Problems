using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                string t = {char(i+'a'),char(j+'a'),char(i+'a')};
                int pos = 0;
                for(int z=0;z<s.size();z++)
                {
                    if(s[z]==t[pos]) pos++;
                    if(pos==3)
                    {
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
    }
};