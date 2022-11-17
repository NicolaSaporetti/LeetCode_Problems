#include <set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<int> myS;
        myS.insert(0);
        while(!myS.empty())
        {
            int pos = *myS.begin();
            if(pos==s.size()) return true;
            for(int i=0;i<wordDict.size();i++)
            {
                int szW = wordDict[i].size();
                if(s.size()-pos>=szW && !s.compare(pos,szW,wordDict[i]))
                {
                    myS.insert(pos+szW);
                }
            }
            myS.erase(myS.begin());
        }
        return false;
    }
};