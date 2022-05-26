#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int newPos=0;
        if(s.size()>=k)
        {
            for(int i=0; i<s.size();i++)
            {
                bool temp_duplicated_found= true;
                int j=1;
                if(i+k-1<s.size())
                {
                    for(; j<k && temp_duplicated_found; j++)
                    {
                        if(s[i+j]!=s[i])
                        {
                            temp_duplicated_found=false;
                            break;
                        }
                    }
                }
                else
                {
                    temp_duplicated_found= false;
                }
                if(!temp_duplicated_found)
                {
                    for(int v=0; v<j; v++)
                    {
                        cout<<s[i+v]<<endl;
                        s[newPos++]=s[i];
                    }
                    i+=j-1;
                }
                else
                {
                    i+=j-1;
                    if(newPos>0)
                    {
                        char value = s[--newPos];
                        s[i--] = s[newPos--];
                        while(newPos>=0 && s[newPos] == value)
                        {
                            s[i--] = s[newPos--];
                        }
                        newPos++;
                    }
                }
            }
            s.resize(newPos);
        }
        return s;
    }
};

int main()
{
    Solution solution;
    return 0;
}