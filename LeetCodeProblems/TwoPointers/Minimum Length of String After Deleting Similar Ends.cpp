using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int p1 = 0;
        int sz = s.size();
        int p2 = sz-1;
        while(p1<p2)
        {
            if(s[p1]!=s[p2]) break;
            char c = s[p1];
            while(s[p1]==c && p1<=p2) p1++;
            while(s[p2]==c && p1<=p2) p2--;
        }
        return p2-p1+1;
    }
};