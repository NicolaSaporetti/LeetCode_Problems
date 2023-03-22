using namespace std;
#include <cassert>
#include <iostream>

template<typename ...Args>
void print()
{
    cout<<endl;
}

template<typename T, typename... Args>
void print(T a, Args... args)
{
    cout<<a<<" ";
    print(args...);
}

int main()
{
    print();
    print('n');
    print('n',1);
    print('n',1,"Ronaldo");
    print('n',1,"Ronaldo",4.57);
}