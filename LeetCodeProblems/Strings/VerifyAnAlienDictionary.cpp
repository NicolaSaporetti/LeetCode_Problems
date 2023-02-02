#include <vector>
using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> number_order(26,0);
        for(int i=0;i<26;i++) number_order[order[i]-'a']=i;
        for(int j=0;j<words.size()-1;j++)
        {
            for(int i=0;i<words[j].size();i++)
            {
                if(i>=words[j+1].size() || number_order[words[j][i]-'a']>number_order[words[j+1][i]-'a']) return false;
                else if(number_order[words[j][i]-'a']<number_order[words[j+1][i]-'a']) break;
            }
        }
        return true;
    }
};