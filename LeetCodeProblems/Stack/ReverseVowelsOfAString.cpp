#include <stack>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        stack<char> vowels;
        for(auto c : s) if(isVowel(c)) vowels.push(c);
        for(auto& c : s) 
        {
            if(isVowel(c))
            {
                c=vowels.top();
                vowels.pop();
            }
        }
        return s;
    }

private:
    bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
                c=='A' || c=='E' || c=='I' || c=='O' || c=='U')? true : false;
    }
};