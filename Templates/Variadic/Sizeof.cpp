using namespace std;
#include <iostream>
#include <array>

template<typename... Ts>
constexpr auto get_type_size()
{
    return array<size_t, sizeof ...(Ts)>{sizeof(Ts)...};
}

int main()
{
    auto arr = get_type_size<short, int, long, long long, float, double>();
    for(auto& e : arr) cout<<e<<" ";
} 