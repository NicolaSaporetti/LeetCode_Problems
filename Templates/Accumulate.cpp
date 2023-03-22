using namespace std;
#include <cassert>

template <size_t N>
constexpr int sum(int const a[])
{
    return a[N-1] + sum<N - 1>(a);
}

template <>
constexpr int sum<0>(int const a[])
{
    return 0;
}

int main()
{
    constexpr int arr[] = {1, 2, 3};
    constexpr int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    static_assert(sum<3>(arr)==6);
    static_assert(sum<7>(arr2)==28);
}