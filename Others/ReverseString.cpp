#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        for(int i=0;i<s.size()/2;i++)
        {
            temp=s[s.size()-1-i];
            s[s.size()-1-i] = s[i];
            s[i]=temp;
        }
    }
};

int main()
{
    vector<char> anagrams = {'b','a','m','b','a'};
    Solution solution;
    solution.reverseString(anagrams);
    for(int i=0; i< anagrams.size(); i++)
    {
        cout<<anagrams[i];
    }
    cout<<endl;
    return 0;
}