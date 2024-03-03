using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int start = 0;
        string res = s+'1';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') k--;
            while(k<0)
            {
                if(s[start++]=='1') k++;
            }
            if(k==0)
            {
                while(s[start]=='0')
                {
                    start++;
                }
                string nres = s.substr(start,i-start+1);
                if(i-start+1<res.size() || (i-start+1==res.size() && nres<res)) res = nres;
            }
        }
        return (res.size()>s.size())? "" : res;
    }
};