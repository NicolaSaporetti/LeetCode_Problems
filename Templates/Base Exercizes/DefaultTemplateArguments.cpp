using namespace std;
#include <iostream>

template<typename T = int>
class foo {};

template<typename T = int, typename T2 = double>
class bar {};

template<typename T = int, typename T2 = double>
void f1() {}

template<typename T = int, typename T2>
void f2() {}

int main()
{
}