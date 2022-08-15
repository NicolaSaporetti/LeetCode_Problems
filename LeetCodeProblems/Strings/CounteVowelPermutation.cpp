#include <iostream>
#include <vector>
using namespace std;

#define A 0
#define E 1
#define I 2
#define O 3
#define U 4

class Solution {
public:
    int countVowelPermutation(int n) {
        int mod = 1000000007;
        long long result = 0;
        long long combinations = 5;
        vector<long long> vowels(5,1);
        vector<long long> temp(5,0);
        while(n>1)
        {
            temp[A]=vowels[E]+vowels[I]+vowels[U];
            temp[E]=vowels[A]+vowels[I];
            temp[I]=vowels[E]+vowels[O];
            temp[O]=vowels[I];
            temp[U]=vowels[I]+vowels[O];
            
            for(int i=0;i<5;i++) vowels[i] = temp[i]%mod;
            n--;
        }
        for(int i=0;i<5;i++)
        {
            result+=vowels[i];
        }
        return result%mod;
    }
};