using namespace std;

class Solution {
public:
    string convertToTitle(int c) {
        string s = "";
        while(c>0)
        {
            c = c - 1;
            s += 'A' + c % 26;
            c /= 26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};