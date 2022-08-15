#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string stack;
        bool error = false;
        for(int i=0;i<s.size() && error == false;i++)
        {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                stack.push_back(s[i]);
            }
            else{
                if(stack.size()>=1 &&
                      ((s[i]==')' && stack[stack.size()-1]=='(') ||
                       (s[i]==']' && stack[stack.size()-1]=='[') ||
                       (s[i]=='}' && stack[stack.size()-1]=='{')))
                {
                    stack.pop_back();
                }
                else error=true;
            }
        }
        if (stack.size()!=0 || error ==true) return false;
        else return true;        
    }
};