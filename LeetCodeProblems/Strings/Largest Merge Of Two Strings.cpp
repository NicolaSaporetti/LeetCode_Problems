using namespace std;

class Solution {
public:
    string largestMerge(string word1, string word2) {
        int p1 = 0;
        int p2 = 0;
        string res = "";
        int sz1 = word1.size();
        int sz2 = word2.size();
        while(p1<sz1 || p2<sz2)
        {
            if(p2>=sz2 || (p1<sz1 && word1[p1]>word2[p2]))
            {
                res.push_back(word1[p1++]);
            }
            else if(p1>=sz1 || (p2<sz2 && word1[p1]<word2[p2]))
            {
                res.push_back(word2[p2++]);
            }
            else
            {
                int i=1;
                while(p1+i<sz1 && p2+i<sz2)
                {
                    if(word1[p1+i]!=word2[p2+i]) break;
                    i++;
                }
                if(p2+i>=sz2 || (p1+i<sz1 && word1[p1+i]>=word2[p2+i])) res.push_back(word1[p1++]);
                else res.push_back(word2[p2++]);
            }
        }
        return res;
    }
};