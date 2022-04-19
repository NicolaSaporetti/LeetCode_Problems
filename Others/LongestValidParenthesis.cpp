#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> temp;
        int maxsize = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == ')')
            {
                if(temp.size()>=1)
                {
                    if(temp[temp.size()-1]==-1)
                    {
                        if(temp.size()>=2 && temp[temp.size()-2]!=-1) // 2(
                        {
                            temp.pop_back();
                            temp[temp.size()-1]+=2;
                            if(temp.size()>=2 && temp[temp.size()-2]!=-1)
                            {
                                temp[temp.size()-2]+=temp[temp.size()-1];
                                temp.pop_back();
                            }
                        }
                        else // (
                        {
                            temp[temp.size()-1]=2;
                        }
                    }
                    else if(temp.size()>=2)  // (2
                    {
                        temp[temp.size()-2]=temp[temp.size()-1]+2;
                        temp.pop_back();
                        if(temp.size()>=2 && temp[temp.size()-2]!=-1)
                        {
                            temp[temp.size()-2]+=temp[temp.size()-1];
                            temp.pop_back();
                        }
                    }
                    else{
                        if(maxsize<temp[temp.size()-1])
                        {
                            maxsize=temp[temp.size()-1];
                        }
                        temp.clear();
                    }
                }
            }
            if(s[i] == '(')
            {
                temp.push_back(-1);
            }
            for(int i=0;i<temp.size();i++)
            {
                cout<<temp[i]<<" ";
            }
            cout<<endl;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]>maxsize) maxsize=temp[i];
            }
            cout<<endl;
        }
        return maxsize;
    }
};

int main()
{
    Solution solution;
    string s = ")(())()())()()()()()";
    //string s = "()(())";
    cout<<solution.longestValidParentheses(s)<<endl;
    return 0;
}