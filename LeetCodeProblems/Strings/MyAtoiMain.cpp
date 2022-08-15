#include <iostream>
#include "MyAtoi.cpp"
using namespace std;

int main()
{
    string s = "1";
    MyAtoi solution;
    cout<<solution.convert(s)<<endl;
    return 0;
}