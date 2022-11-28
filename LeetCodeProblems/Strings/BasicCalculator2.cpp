#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> st1;
        int ans = 0;
        char sign = '+';
        
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]>='0' && s[i]<='9'){
                int val = 0;
                while(s[i]>='0' && s[i]<='9' && i<s.size()){
                    val = val * 10 + (s[i]-'0');
                    i++;
                }
                i--;
                if(sign == '/'){
                    int a = st1.top();
                    st1.pop();
                    int tmp = a/val;
                    st1.push(tmp);
                }
                else if(sign == '*'){
                    int a = st1.top();
                    st1.pop();
                    st1.push(a*val);
                }
                else if(sign == '+'){
                    st1.push(val);
                }
                else if(sign == '-'){
                    st1.push(val*(-1));
                }
            }
            else if(s[i] != ' '){
                sign = s[i];
            }
            
        }
        while(!st1.empty()){
            ans += st1.top();
            st1.pop();   
        }
        return ans;
    }
};