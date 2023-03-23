using namespace std;
#include <iostream>

template<typename T>
constexpr T NewLine = T('\n');

int main()
{
    wstring test = L"demo";
    test+=NewLine<wchar_t>;
    wcout<<test<<endl;
}