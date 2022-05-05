#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "MyAtoi.cpp"
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        MyAtoi atoi;
        long long int n1 = static_cast<long long int>(atoi.convert(num1));
        long long int n2 = static_cast<long long int>(atoi.convert(num2));
        long long int sol = n1*n2;
        string solution;
        vector<char> solvect;
        for(int i=0;sol>0;i++)
        {
            solvect.push_back(sol%10+48);
            sol/=10;
            cout<<solvect[i]<<endl;
        }
        cout<<"Size: "<<solvect.size()<<endl;
        for(int i=solvect.size()-1;i>=0;i--)
        {
            solution.push_back(solvect[i]);
        }
        return solution;
    }
};

int main()
{
    string s1 = "12";
    string s2 = "12";
    Solution solution;
    cout<<solution.multiply(s1,s2)<<endl;
    return 0;
}