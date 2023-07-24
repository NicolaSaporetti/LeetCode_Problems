using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        bool seq = false;
        int p = '0';
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                if(p=='0')
                {
                    if(seq) return false;
                    else seq=true;
                }
            }
            p = s[i];
        }
        return true;
    }
};