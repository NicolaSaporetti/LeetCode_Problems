#include <vector>
using namespace std;

class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int sz = words.size();
        int r = 0;
        vector<int> v(26);
        for(auto e : letters) v[e-'a']++;
        for(int i=0;i<(1<<sz);i++)
        {
            vector<int> v1(26,0);
            for(int j=0;j<sz;j++)
                if((1<<j)&i)
                    for(auto e : words[j]) v1[e-'a']++;
            bool isOk = true;
            for(int j=0;j<26 && isOk;j++) if(v1[j]>v[j]) isOk = false;
            if(isOk)
            {
                int t = 0;
                for(int j=0;j<26;j++) t+=score[j]*v1[j];
                r = max(r, t);
            }
        }
        return r;
    }
};