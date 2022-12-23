using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto& w : words)
        {
            if(isPalindrome(w)) return w;
        }
        return "";
    }
    
private:
    bool isPalindrome(string& s)
    {
        int sz = s.size();
        for(int i=0;i<sz/2;i++)
        {
            if(s[i]!=s[sz-1-i]) return false;
        }
        return true;
    }
};