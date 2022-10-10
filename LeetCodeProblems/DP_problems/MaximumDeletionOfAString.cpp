using namespace std;

class Solution {
public:
    int deleteString(string s) {
        dp.assign(s.size()+1,0);
        f(s,0,0);
        int res = 0;
        for(int i=0;i<s.size();i++) res = max(dp[i],res);
        return max(dp[s.size()],res+1);
    }
    
private:
    void f(string& s, int pos, int rec)
    {
        if(pos>=s.size()-1) dp[s.size()] = max(dp[s.size()],rec+1);
        for(int i=0;i<(s.size()-pos)/2;i++)
        {
            if(dp[pos+i+1]<rec+1 && s.compare(pos,i+1,s,pos+i+1,i+1)==0)
            {
                dp[pos+i+1]=rec+1;
                f(s,pos+i+1,rec+1);
            }
        }
    }
        
    vector<int> dp;
};