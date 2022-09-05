using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        
        int n =s.length();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0') cnt++;
        }
        int pow=1,curr=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1')
            {
                curr +=pow;
                if(curr<=k) cnt++;
            }
            if(pow>k || curr>k) break;
            pow*=2;
        }
        return cnt;
    }
};