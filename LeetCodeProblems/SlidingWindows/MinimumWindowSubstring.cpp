#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> windowsComposition(60,0);
        vector<int> wordComposition(60,0);
        int wz=0;
        int res = INT_MAX;
        int start = 0;
        for(int i=0;i<t.size();i++) wordComposition[t[i]-'A']++;
        for(int i=0;i<s.size();i++) 
        {
            wz++;
            windowsComposition[s[i]-'A']++;
            if(verityComposition(windowsComposition, wordComposition))
            {
                while(wz>0 && removeUselessLetter(windowsComposition, wordComposition, s[i-wz+1]-'A'))
                {
                    wz--;
                    windowsComposition[s[i-wz]-'A']--;
                }
                if(wz<res)
                {
                    res = wz;
                    start = i-wz+1;
                }
                wz--;
                windowsComposition[s[i-wz]-'A']--;
                while(wz>0 && removeUselessLetter(windowsComposition, wordComposition, s[i-wz+1]-'A'))
                {
                    wz--;
                    windowsComposition[s[i-wz]-'A']--;
                }
            }
        }
        return (res != INT_MAX)? s.substr(start,res) : "";
    }
private:
    bool verityComposition(vector<int>& windowsComposition, vector<int>& wordComposition)
    {
        for(int i=0;i<60;i++)
        {
            if(windowsComposition[i]<wordComposition[i]) return false;
        }
        return true;
    }
    
    bool removeUselessLetter(vector<int>& windowsComposition, vector<int>& wordComposition, int letter)
    {
        if(windowsComposition[letter]-1<wordComposition[letter]) return false;
        else return true;
    }
};