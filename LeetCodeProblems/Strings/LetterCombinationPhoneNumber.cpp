#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return solutions;
        word.resize(digits.size());
        comb = {{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        fillCell(digits,0);
        return solutions;
    }
    
private:
    void fillCell(string& digits, int pos)
    {
        if(pos>=digits.size()) solutions.push_back(word);
        else
        {
            for(int i=0;i<comb[digits[pos]-'2'].size();i++)
            {
                word[pos]=comb[digits[pos]-'2'][i];
                fillCell(digits,pos+1);
            }
        }
    }

    string word;
    vector<string> solutions;
    vector<vector<char>> comb;
};