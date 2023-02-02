using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        simplify(s);
        simplify(t);
        return s==t;
    }
private:
    void simplify(string& s)
    {
        int pos = 0;
        for(auto& c : s)
        {
            if(c=='#')
            {
                if(pos!=0) pos--;
            }
            else s[pos++]=c;
        }
        s.resize(pos);
    }
};