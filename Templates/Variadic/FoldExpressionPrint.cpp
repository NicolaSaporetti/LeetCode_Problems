#include <iostream>
using namespace std;

template<typename... Args>
void printl(Args... args)
{
    (...,(cout<<args))<<'\n';
}

template<typename... Args>
void printr(Args... args)
{
    ((cout<<args),...)<<'\n';
}

int main()
{
    printl("do","berma",'n');
    printr("do","berma",'n');
}