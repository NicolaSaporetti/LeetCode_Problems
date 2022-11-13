#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        sz = words[0].size();
        vector<int> result;
        for(int j=0;j<sz;j++)
        {
            wordsToMatch = words.size();
            fillMap(words);
            int start = j;
            for(int i=start;start+sz<=s.size();i+=sz)
            {
                string word = s.substr(i,sz);
                if(m.find(word)==m.end())
                {
                    putWordsBackInMap(start,i,s);
                    start = i+sz;
                }
                else
                {
                    m[word]--;
                    wordsToMatch--;
                    while(m[word]<0)
                    {
                        m[s.substr(start,sz)]++;
                        wordsToMatch++;
                        start+=sz;
                    }
                    if(wordsToMatch==0) result.push_back(start);
                }
            }
        }
        return result;
    }
    
private:
    void fillMap(vector<string>& words)
    {
        m.clear();
        for(int i=0;i<wordsToMatch;i++) m[words[i]]++;
    }
    
    void putWordsBackInMap(int start, int end, string& s)
    {
        for(int i=start;i<end;i+=sz)
        {
            m[s.substr(i,sz)]++;
            wordsToMatch++;
        }
    }
    
    int sz;
    int wordsToMatch;
    unordered_map<string,int> m;
};