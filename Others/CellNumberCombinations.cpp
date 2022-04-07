#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    void initialize(string digits)
    {
        solutions.clear();
        temp.resize(digits.size());
        Localdigits = digits;
    }

    void fillCell(int positionToFill)
    {
        if(positionToFill<Localdigits.size())
        {
            switch(Localdigits[positionToFill])
            {
                case '2':
                temp[positionToFill]='a';
                fillCell(positionToFill+1);
                temp[positionToFill]='b';
                fillCell(positionToFill+1);
                temp[positionToFill]='c';
                fillCell(positionToFill+1);
                break;
                case '3':
                temp[positionToFill]='d';
                fillCell(positionToFill+1);
                temp[positionToFill]='e';
                fillCell(positionToFill+1);
                temp[positionToFill]='f';
                fillCell(positionToFill+1);
                break;
                case '4':
                temp[positionToFill]='g';
                fillCell(positionToFill+1);
                temp[positionToFill]='h';
                fillCell(positionToFill+1);
                temp[positionToFill]='i';
                fillCell(positionToFill+1);
                break;
                case '5':
                temp[positionToFill]='j';
                fillCell(positionToFill+1);
                temp[positionToFill]='k';
                fillCell(positionToFill+1);
                temp[positionToFill]='l';
                fillCell(positionToFill+1);
                break;
                case '6':
                temp[positionToFill]='m';
                fillCell(positionToFill+1);
                temp[positionToFill]='n';
                fillCell(positionToFill+1);
                temp[positionToFill]='o';
                fillCell(positionToFill+1);
                break;
                case '7':
                temp[positionToFill]='p';
                fillCell(positionToFill+1);
                temp[positionToFill]='q';
                fillCell(positionToFill+1);
                temp[positionToFill]='r';
                fillCell(positionToFill+1);
                temp[positionToFill]='s';
                fillCell(positionToFill+1);
                break;
                case '8':
                temp[positionToFill]='t';
                fillCell(positionToFill+1);
                temp[positionToFill]='u';
                fillCell(positionToFill+1);
                temp[positionToFill]='v';
                fillCell(positionToFill+1);
                break;
                case '9':
                temp[positionToFill]='w';
                fillCell(positionToFill+1);
                temp[positionToFill]='x';
                fillCell(positionToFill+1);
                temp[positionToFill]='y';
                fillCell(positionToFill+1);
                temp[positionToFill]='z';
                fillCell(positionToFill+1);
                break;
            }
        }
        else{
            solutions.push_back(temp);
        }
        return;
    }
public:
    vector<string> letterCombinations(string digits) {
        initialize(digits);
        if(digits.size()) fillCell(0);
        return solutions;
    }

    vector<string> solutions;
    string temp;
    string Localdigits;
};

int main()
{
    string phoneNumber = "23";
    Solution solution;
    vector<string> possibleNumbers = solution.letterCombinations(phoneNumber);
    for(int i=0;i<possibleNumbers.size(); i++)
    {
        cout<<"Sol: "<<possibleNumbers[i]<<endl;
    }
    return 0;
}