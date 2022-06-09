#include <iostream>
using namespace std;

#define C 67
#define D 68
#define I 73
#define L 76
#define M 77
#define V 86
#define X 88

class Solution {
public:
    int romanToInt(string s) {
        int solution = 0;
        for(int i=0; i<s.size();i++)
        {
            switch(s[i])
            {
                case C:
                if(i+1<s.size() && s[i+1] == M)
                {
                    solution +=900;
                    i++;
                }
                else if(i+1<s.size() && s[i+1] == D)
                {
                    solution +=400;
                    i++;
                }
                else{
                    solution +=100;
                }
                break;
                case D:
                solution +=500;
                break;
                case I:
                if(i+1<s.size() && s[i+1] == V)
                {
                    solution +=4;
                    i++;
                }
                else if(i+1<s.size() && s[i+1] == X)
                {
                    solution +=9;
                    i++;
                }
                else
                {
                    solution +=1;
                }
                break;
                case L:
                solution +=50;
                break;
                case M:
                    solution +=1000;
                break;
                case V:
                solution +=5;
                break;
                case X:
                if(i+1<s.size() && s[i+1] == L)
                {
                    solution +=40;
                    i++;
                }
                else if(i+1<s.size() && s[i+1] == C)
                {
                    solution +=90;
                    i++;
                }
                else
                {
                    solution +=10;
                }
                break;
            }
        }
        return solution;
    }
};