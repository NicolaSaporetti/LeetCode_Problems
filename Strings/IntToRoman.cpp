#include <iostream>
#include <stdlib.h>
#include <string>
#define C 67
#define D 68
#define I 73
#define L 76
#define M 77
#define V 86
#define X 88

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int value[4];
        string s;
        int position = 0;
        s.resize(15);
        for(int i=0; i<4; i++)
        {
            value[i] = num%10;
            num/=10;
        }
        if(value[3]!=0)
        {
            for(int i=0;i<value[3];i++)
            {
                s[position++] = M;
            }
        }
        if(value[2]!=0)
        {
            if(value[2]==9)
            {
                s[position++] = C;
                s[position++] = M;
            }
            else if(value[2]<=8 && value[2]>=5)
            {
                s[position++] = D;
                for(int i=0;i<value[2]-5;i++)
                {
                    s[position++] = C;
                }
            } else if(value[2]==4)
            {
                s[position++] = C;
                s[position++] = D;
            }
            else
            {
                for(int i=0;i<value[2];i++)
                {
                    s[position++] = C;
                }
            }
        }
        if(value[1]!=0)
        {
            if(value[1]==9)
            {
                s[position++] = X;
                s[position++] = C;
            }
            else if(value[1]<=8 && value[1]>=5)
            {
                s[position++] = L;
                for(int i=0;i<value[1]-5;i++)
                {
                    s[position++] = X;
                }
            } else if(value[1]==4)
            {
                s[position++] = X;
                s[position++] = L;
            }
            else
            {
                for(int i=0;i<value[1];i++)
                {
                    s[position++] = X;
                }
            }
        }
        if(value[0]!=0)
        {
            if(value[0]==9)
            {
                s[position++] = I;
                s[position++] = X;
            }
            else if(value[0]<=8 && value[0]>=5)
            {
                s[position++] = V;
                for(int i=0;i<value[0]-5;i++)
                {
                    s[position++] = I;
                }
            } else if(value[0]==4)
            {
                s[position++] = I;
                s[position++] = V;
            }
            else
            {
                for(int i=0;i<value[0];i++)
                {
                    s[position++] = I;
                }
            }
        }
        s.resize(position);
        return s;
    }
};

int main()
{
    Solution solution;
    int result = 58;
    cout<<solution.intToRoman(result)<<endl;
    return 0;
}