using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int total = 0;
        int val = 0;
        for(int i=0;i<s.size();i++)
        {
            if(i>0 && s[i-1]==s[i]-1) val++;
            else val = 1;
            total = max(total, val);
        }
        return total;
    }
};