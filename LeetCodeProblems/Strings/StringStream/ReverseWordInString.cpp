#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string sol;
        stack<string> st;
        stringstream ss (s);
        string word;
        while (ss >> word) st.push(word);
        while(!st.empty())
        {
            sol+=st.top()+' ';
            st.pop();
        }
        sol.pop_back();
        return sol;
    }
};