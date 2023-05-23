using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string result;
        for(int i=0;i<s.size();i++)
        {
            if(i+2<s.size() && s[i+2]=='#')
            {
                result.push_back('a'+(s[i]-'0')*10+s[i+1]-'0'-1);
                i+=2;
            }
            else
            {
                result.push_back('a'+s[i]-'0'-1);
            }
        }
        return result;
    }
};