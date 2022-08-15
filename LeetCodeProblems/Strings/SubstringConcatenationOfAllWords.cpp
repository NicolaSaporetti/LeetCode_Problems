#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        sz = words[0].size();
        for(int j=0;j<sz;j++)
        {
            wordsToMatch = words.size();
            fillMap(words);
            start = j;
            for(int i=start;i+sz<=s.size();i+=sz)
            {
                string word = s.substr(i,sz);
                if(m.find(word)==m.end())
                {
                    removeAllWords(start,i,s);
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
        for(int i=0;i<wordsToMatch;i++)
        {
            m[words[i]]++;
        }
    }
    
    void removeAllWords(int start, int end, string& s)
    {
        for(int i=start;i<end;i+=sz)
        {
            m[s.substr(i,sz)]++;
            wordsToMatch++;
        }
    }
    
    int start;
    int sz;
    int wordsToMatch;
    vector<int> result;
    map<string,int> m;
};