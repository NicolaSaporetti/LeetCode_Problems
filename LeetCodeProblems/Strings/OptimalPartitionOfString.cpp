#include <vector>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        vector<bool> letters(26,false);
        int res = 1;
        for(int i=0;i<s.size();i++)
        {
            if(letters[s[i]-'a']==true)
            {
                letters.assign(26,false);
                letters[s[i]-'a']=true;
                res++;
            }
            else letters[s[i]-'a']=true;
        }
        return res;
    }
};