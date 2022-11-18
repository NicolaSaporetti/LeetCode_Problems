#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stack;
        for(auto i: tokens){
            if(i == "+" || i == "*" || i == "/" || i == "-"){
                long long e1 = stack.top();
                stack.pop();
                long long e2 = stack.top();
                stack.pop();
                if(i == "+"){
                    stack.push(e1+e2);
                }
                else if(i == "-"){
                    stack.push(e2-e1);
                }
                else if(i == "*"){
                    stack.push(e1*e2);
                }
                else if(i == "/"){
                    stack.push(e2/e1);
                }
            }
            else
                stack.push(stoi(i));
        }
        return stack.top();
    }
};