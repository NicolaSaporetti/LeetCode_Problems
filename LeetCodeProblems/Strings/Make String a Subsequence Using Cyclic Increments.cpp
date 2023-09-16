using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int j=0;
        for(int i=0;i<str1.size() && j<str2.size();i++)
        {
            char l = str1[i];
            char l1 = ((l-'a')+1)%26+'a';
            char t = str2[j];
            if(l==t || l1==t) j++;
        }
        return j>=str2.size();        
    }
};