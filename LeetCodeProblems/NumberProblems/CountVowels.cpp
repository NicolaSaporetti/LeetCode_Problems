#include <iostream>
#include <array>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        array<int,5> vowelsNumber={1,1,1,1,1};
        for(int i=2;i<=n;i++)
        {
            vowelsNumber[4]=vowelsNumber[0]+vowelsNumber[1]+
               vowelsNumber[2]+vowelsNumber[3]+vowelsNumber[4];
            vowelsNumber[3]+=(i*(i+1))/2;
            vowelsNumber[2]+=i;
            vowelsNumber[1]++;
        }
        return vowelsNumber[0]+vowelsNumber[1]+vowelsNumber[2]+vowelsNumber[3]+vowelsNumber[4];
    }
};