#include <vector>
using namespace std;

class Solution {
public:
    int countVowelSubstrings(string word) {
        vector<int> v;
        int tot = 0;
        for(int i=0;i<word.size();i++)
        {
            v.assign(5,0);
            for(int j=i;j<word.size();j++)
            {
                if(word[j]=='a') v[0]++;
                else if(word[j]=='e') v[1]++;
                else if(word[j]=='i') v[2]++;
                else if(word[j]=='o') v[3]++;
                else if(word[j]=='u') v[4]++;
                else break;
                tot+=all_of(begin(v),end(v),[](int elem){return elem>0;});
            }
        }
        return tot;
    }
};