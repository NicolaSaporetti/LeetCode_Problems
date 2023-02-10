using namespace std;

class Solution {
public:
    int minimumMoves(string s) {
        int tot = 0;
        for(int i=0;i<s.size();)
        {
            if(s[i]=='X')
            {
                for(int j=0;j<3 && i<s.size();j++,i++) s[i]='O';
                tot++;
            }
            else i++;
        }
        return tot;
    }
};