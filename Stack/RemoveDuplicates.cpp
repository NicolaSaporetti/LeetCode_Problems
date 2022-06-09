#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> myStack;
        for(int i=0; i<s.size();i++)
        {
            if(myStack.empty() || s[i]!=myStack.top())
            {
                myStack.push(s[i]);
            }
            else
            {
                myStack.pop();
            }
        }
        int sz=myStack.size();
        for(int i=sz-1; i>=0;i--)
        {
            s[i]=myStack.top();
            myStack.pop();
        }
        s.resize(sz);
        return s;
    }
};