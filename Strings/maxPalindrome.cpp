#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    void resetDuplicated(bool duplicated[]) {
        for(int i=0; i<256;i++)
        {
            duplicated[i] = false;
        }
    }
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        bool duplicated[256];
        for(int i=0; i<s.size();i++)
        {
            int length = 0;
            resetDuplicated(duplicated);
            if((int)s[i+length]>256 || (int)s[i+length]<0)
            {
                return 0;
            }
            do {
                duplicated[(int)s[i+length]] = true;
                length++;
                if((int)s[i+length]>256 || (int)s[i+length]<0)
                {
                    return 0;
                }
            } while((i+length<s.size()) && duplicated[(int)s[i+length]]==false);
            
            if(length>maxLength)
            {
                maxLength = length;
            }
        }
        return maxLength;
    }
};