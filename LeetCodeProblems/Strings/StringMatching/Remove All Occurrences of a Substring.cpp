using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.size()>=part.size())
        {
            auto pos = s.find(part);
            if(pos!=string::npos)
            {
                s = s.substr(0,pos)+s.substr(pos+part.size(),s.size());
            }
            else break;
        }
        return s;
    }
};