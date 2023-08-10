#include <string>
using namespace std;

bool isPalindrome(string& s, int st, int e)
{
    int sz = e-st+1;
    for(int i=0;i<sz/2;i++)
    {
        if(s[st+i]!=s[st+sz-1-i]) return false;
    }
    return true;
}