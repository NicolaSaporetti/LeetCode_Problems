using namespace std;

class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int s = 0;
        int r = 0;
        char n1 = 'a';
        char n2 = 'a';
        for(int i=0;i<word.size();i++)
        {
            if(n1!=word[i] && word[i]!=n2)
            {
                if(word[i]=='a')
                {
                    s=i;
                    n1 = 'e';
                    n2 = 'a';
                }
                else
                {
                    s=i+1;
                    n1 = 'a';
                    n2 = 'a';
                }
            }
            else
            {
                if(n1==word[i])
                {
                    switch(word[i])
                    {
                        case 'a':
                            n1 = 'e';
                            break;
                        case 'e':
                            n1 = 'i';
                            break;
                        case 'i':
                            n1 = 'o';
                            break;
                        case 'o':
                            n1 = 'u';
                            break;
                        case 'u':
                            r = max(r, i+1-s);
                            break;
                    }
                    n2 = word[i];
                }
                if(n2=='u') r = max(r,i+1-s);
            }
        }
        return r;
    }
};