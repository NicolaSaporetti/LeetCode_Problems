#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        string temp;
        int tempSize = 0;
        temp.clear();
        int maxsize = 0;
        int size = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ')')
            {
                if(temp.size()>=1)
                {
                    temp = temp.substr(0,temp.size()-1);
                    if(temp.size()==0)
                    {
                        size=size+2+tempSize;
                        cout<<"Ext: "<<2+tempSize<<endl;
                        tempSize = 0;
                    }
                    else
                    {
                        tempSize+=2;
                        cout<<"Int"<<endl;
                    }
                }
                else
                {
                    temp.clear();
                    if(size>maxsize) maxsize= size;
                    tempSize = 0;
                    size = 0;
                    cout<<"Reset"<<endl;
                }
            }
            if(s[i] == '(')
            {
                temp+='(';
            }
        }
        size = 0;
        if(size>maxsize)maxsize= size;
        return maxsize;
    }
};

int main()
{
    Solution solution;
    string s = ")(())()())()()()()()";((()(
    cout<<solution.longestValidParentheses(s)<<endl;
    return 0;
}