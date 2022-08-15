#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = {};
        result.resize(s.size());
        if(numRows == 1)
        {
            for(int i=0; i<s.size(); i++)
            {
                result[i] = s[i];
            }
        }
        else{
            int element = 0;
            for(int i=0; i<numRows;i++)
            {
                if(i==0 || i==numRows-1)
                {
                    for(int j=i; j<s.size(); j+=2*(numRows - 1))
                    {
                        result[element] = s[j];
                        element++;
                    }
                }
                else{
                    bool FirstAngle = true;
                    int j=i;
                    while (j<s.size())
                    {
                        result[element] = s[j];
                        element++;

                        if(FirstAngle == true)
                        {
                            j+= 2*(numRows - i - 1);
                        }
                        else{
                            j+= 2*i;
                        }
                        FirstAngle = !FirstAngle;
                    }
                }
            }
        }
        return result;
    }
};