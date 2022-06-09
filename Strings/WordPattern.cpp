#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
    map<char,string> myM;
    map<string,char> myM2;
    
    string getWord(string& s, int& i)
    {
        int start = i;
        int end = 0;
        while(i<s.size() && s[i]!=' ')
        {
            i++;
        }
        end = i++;
        return s.substr(start,end-start);
    }
public:
    bool wordPattern(string pattern, string s) {
        int j=0;
        int i=0;
        map<char,string>::iterator it;
        map<string, char>::iterator it2;
        for(;i<pattern.size()&&j<s.size();i++)
        {
            string word = getWord(s,j);
            it = myM.find(pattern[i]);
            it2 = myM2.find(word);
            if(it!=myM.end() || it2!=myM2.end())
            {
                if(it->second.compare(word)!=0 || it2->second!=pattern[i]) return false;
            }
            else
            {
                myM.insert(make_pair(pattern[i],word));
                myM2.insert(make_pair(word,pattern[i]));
            }
        }
        return (j>=s.size() && i>=pattern.size())?true:false;
    }
};