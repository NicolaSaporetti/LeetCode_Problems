#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    void initialize(int n)
    {
        solutions.clear();
        temp.resize(n*2);
    }
    void fillCell(int parenthesisLeft, int leftParOpen, int positionToFill)
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
        if(parenthesisLeft==0 && leftParOpen==0){
            solutions.push_back(temp);
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        initialize(n);
        fillCell(n,0,0);
        return solutions;
    }

    vector<string> solutions;
    string temp;
};

int main()
{
    Solution solution;
    vector<string> possibleNumbers = solution.generateParenthesis(3);
    for(int i=0;i<possibleNumbers.size(); i++)
    {
        cout<<"Sol: "<<possibleNumbers[i]<<endl;
    }
    return 0;
}