using namespace std;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1) return "";
        else
        {
            bool changed = false;
            for(int i=0;i<palindrome.size()/2 && !changed;i++)
                if(palindrome[i]!='a')
                {
                    palindrome[i] = 'a';
                    changed = true;
                }
            if(!changed) palindrome[palindrome.size()-1]='b';
            return palindrome;
        }
    }
};