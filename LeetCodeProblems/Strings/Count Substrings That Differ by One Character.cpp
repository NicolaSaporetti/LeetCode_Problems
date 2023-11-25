using namespace std;

class Solution {
public:
    int countSubstrings(string s, string t) {
        int sz = s.size();
        int sz1 = t.size();
        int res = 0;
        for(int i=0;i<sz;i++)
        {
            string r;
            for(int j=0;i+j<sz;j++)
            {
                r+=s[i+j];
                int temp = 0;
                for(int k=0;k<=sz1-r.size();k++)
                {
                    int d = 0;
                    for(int y=0;y<r.size() && d<=1;y++) if(t[k+y]!=r[y]) d++;
                    if(d==1) temp++;
                }
                if(temp>0) res+=temp;
            }
        }
        return res;
    }
};