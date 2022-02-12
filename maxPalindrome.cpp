#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 1;
        string result = {s[0]};
        for(int i=1; i<s.size();i++)
        {
            int length = 1;
            bool Palindrom = true;
            while(Palindrom==true && (i-length>=0) && (i+length<s.size()))
            {
                if(s[i-length]==s[i+length])
                {
                    length++;
                }
                else
                    Palindrom = false;

            }
            length--;
            if(length>(maxLength-1)/2)
            {
                maxLength = length*2+1;
                result = s.substr(i-length,maxLength); 
            }
        }
        if(s.size()>=2)
        {
            for(int i=0; i<s.size();i++)
            {
                int length = 0;
                bool Palindrom = true;
                while(Palindrom==true && (i-length>=0) && (i+1+length<s.size()))
                {
                    if(s[i-length]==s[i+length+1])
                    {
                        length++;
                    }
                    else
                        Palindrom = false;

                }
                cout<<maxLength<<endl;
                cout<<length*2<<endl;
                if(length*2>maxLength)
                {
                    maxLength = length*2;
                    result = s.substr(i-length+1,maxLength);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string result = "bb";
    cout<<solution.longestPalindrome(result)<<endl;
    return 0;
}