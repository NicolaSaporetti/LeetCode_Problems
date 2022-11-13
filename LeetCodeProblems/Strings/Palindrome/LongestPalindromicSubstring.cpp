using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxSize = 0;
        int pos = -1;
        int sz = s.size();
        for(int i=0;i<s.size();i++)
        {
            int size = 1;
            while(i-size>=0 && i+size<sz && s[i-size]==s[i+size]) size++;
            if((size-1)*2+1>maxSize)
            {
                maxSize = (size-1)*2+1;
                pos = i;
            }
            size = 1;
            while(i-size+1>=0 && i+size<sz && s[i-size+1]==s[i+size]) size++;
            if((size-1)*2>maxSize)
            {
                maxSize = (size-1)*2;
                pos = i;
            }
        }
        return s.substr(pos-(maxSize-1)/2,maxSize);
    }
};