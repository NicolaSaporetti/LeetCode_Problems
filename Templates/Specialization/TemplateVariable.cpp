using namespace std;
#include <iostream>

template<typename T>
constexpr T separator = '\n';

template<>
constexpr wchar_t separator<wchar_t> = L'\n';

template<typename T>
basic_ostream<T>& show_parts(basic_ostream<T>& s, basic_string_view<T> const& str)
{
    using size_type = typename basic_string_view<T>::size_type;
    size_type start = 0;
    size_type end;
    do
    {
        end = str.find(separator<T>,start);
        s<<'['<<str.substr(start,end-start)<<']'<<separator<T>;
        start = end+1;
    } while (end!=string::npos);
    return s;
}

int main()
{
    basic_string_view<char> s = "Attack\nis\nnot\nfor\nfree";
    show_parts(cout,s);
}