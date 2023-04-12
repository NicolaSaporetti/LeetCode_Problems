#include <vector>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        position.assign(26,0);
        for(int i=0;i<26;i++) position[order[i]-'a']=i;
        for(int i=1;i<words.size();i++)
        {
            if(!isbefore(words[i-1],words[i])) return false;
        }
        return true;
    }
private:
    bool isbefore(string& s1, string& s2)
    {
        int pos = 0;
        while(s1.size()>pos && s2.size()>pos)
        {
            int pos1 = position[s1[pos]-'a'];
            int pos2 = position[s2[pos]-'a'];
            if(pos1<pos2) return true;
            else if(pos1>pos2) return false;
            else pos++;
        }
        if(s1.size()>pos && s2.size()<=pos) return false;
        return true;
    }

    vector<int> position;
};