#include <iostream>

using namespace std;

class Solution {
private:
public:
    int percentageLetter(string s, char letter) {
        int count =0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==letter)
            {
                count++;
            }
        }
        return count/s.size();
    }
};

int main()
{
    Solution solution;
    return 0;
}