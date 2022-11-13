#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        temp.resize(n*2);
        fillCell(n,0,0);
        return solutions;
    }
    
private:
    void fillCell(int parenthesisLeft, int leftParOpen, int positionToFill)
    {   
        if(parenthesisLeft==0 && leftParOpen==0) solutions.push_back(temp);
        else
        {
            if(parenthesisLeft>0)
            {
                temp[positionToFill]='(';
                fillCell(parenthesisLeft-1, leftParOpen+1, positionToFill+1);
            }
            if(leftParOpen>0)
            {
                temp[positionToFill]=')';
                fillCell(parenthesisLeft, leftParOpen-1, positionToFill+1);
            }
        }
        return;
    }

    vector<string> solutions;
    string temp;
};