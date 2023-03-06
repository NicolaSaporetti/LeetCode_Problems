#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        prev = chars[0];
        tot = 1;
        pos = 0;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==prev) tot++;
            else
            {
                fillNum(chars);
                prev = chars[i];
                tot = 1;
            }
        }
        fillNum(chars);
        chars.resize(pos);
        return pos;
    }
private:
    void fillNum(vector<char>& chars)
    {
        chars[pos++]=prev;
        if(tot>1)
        {
            vector<int> num;
            while(tot>0)
            {
                num.push_back(tot%10);
                tot/=10;
            }
            for(int j=num.size()-1;j>=0;j--) chars[pos++]=num[j]+'0';
        }
    }

int pos;
int tot;
char prev;
};