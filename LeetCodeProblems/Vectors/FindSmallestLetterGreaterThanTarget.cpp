#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = upper_bound(letters.begin(),letters.end(),target)-letters.begin();
        if(i<letters.size()) return letters[i];
        else return letters[0];
    }
};