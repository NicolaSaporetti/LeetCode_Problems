#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(const string& s) {
        stack<int> multiplierS;
        stack<string> stringS;
        multiplierS.push(1);
        stringS.push("");
        
        int currMultiplier = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                currMultiplier *= 10;
                currMultiplier += (s[i] - '0');
            }
            else if (s[i] == '[') {
                stringS.push("");
                multiplierS.push(currMultiplier);
                currMultiplier = 0;
            }
            else if (s[i] == ']') {
                int topMult = multiplierS.top(); multiplierS.pop();
                string topS = stringS.top(); stringS.pop();
                
                string decodedTop = selfConcat(topS, topMult);
                topS = stringS.top(); stringS.pop();
                
                stringS.push(topS + decodedTop);
            }
            else {
                stringS.top().push_back(s[i]);
            }
        }
        return stringS.top();
    }
private:
    string selfConcat(const string& s, int times) {
        string out;
        for (int i = 0; i < times; ++i) {
            out.append(s);
        }
        return out;
    }
};