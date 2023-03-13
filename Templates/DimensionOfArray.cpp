using namespace std;
#include <cassert>

template<typename T>
struct Rank {
    static constexpr unsigned int dim = 0;
};

template<typename T>
struct Rank<T[]>
{
    static constexpr unsigned int dim = 1+Rank<T>::dim;
};

template<typename T, size_t N>
struct Rank<T[N]>
{
    static constexpr unsigned int dim = 1+Rank<T>::dim;
};

int main()
{
    int a;
    int b[2];
    int c[2][3];
    float d[2][3][2][2][2];
    static_assert(Rank<int[]>::dim==1);
    static_assert(Rank<int[][2]>::dim==2);
    static_assert(Rank<double[][3][4]>::dim==3);
    static_assert(Rank<decltype(a)>::dim==0);
    static_assert(Rank<decltype(b)>::dim==1);
    static_assert(Rank<decltype(c)>::dim==2);
    static_assert(Rank<decltype(d)>::dim==5);
}