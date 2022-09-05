using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int sz = s.size();
        int total = 0;
        bool bar = false;
        for(int i=0;i<sz;i++)
        {
            if(s[i]=='*' && !bar) total++;
            if(s[i]=='|') bar = !bar;
        }
        return total;
    }
};