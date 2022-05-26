#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
public:
    int percentageLetter(string s, char letter) {
        int count =0;
        for(int i=0;i<s.size();i++)
        {
            cout<<"I: "<<i<<endl;
            cout<<s[i]<<endl;
            cout<<letter<<endl;
            if(s[i]==letter)
            {
                cout<<"Found"<<endl;
                count++;
            }
        }
        return count/s.size();
    }
};

int main()
{
    string a = "foobar";
    Solution solution;
    cout<<solution.percentageLetter(a,'o')<<endl;
    return 0;
}