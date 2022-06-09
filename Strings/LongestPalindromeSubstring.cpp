class Solution {
private:
    int maxSize;
    string result;
    void updatePalindrome(int size, int start, string& s)
    {
        if(maxSize<size)
        {
            maxSize = size;
            result=s.substr(start,maxSize);
        }
    }
public:
    string longestPalindrome(string s) {
        maxSize = -1;
        for(int i=0;i<s.size();i++)
        {
            int size =0;
            int j=0;
            for(;i+j+1<s.size() && i-j>=0;j++)
            {
                if(s[i+j+1]!=s[i-j]) break;
                size+=2;
            }
            updatePalindrome(size,i-j+1,s);

            size = 1;
            for(j=1;i+j<s.size() && i-j>=0;j++)
            {
                if(s[i+j]!=s[i-j]) break;
                size+=2;
            }
            updatePalindrome(size,i-j+1,s);
        }
        return result;
    }
};