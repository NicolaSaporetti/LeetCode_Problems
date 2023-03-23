using namespace std;

namespace ns
{
    template<typename T>
    struct wrapper
    {
        T value;
    };
    template struct wrapper<int>;

    template<typename T>
    T add(T a, T b)
    {
        return a+b;
    }
    template int add(int,int);
}

template<typename T>
class foo
{
    struct bar {};
    T f(bar const arg) { return {};}
};

using namespace ns;
template struct wrapper<double>;
template double add(double,double);
template int foo<int>::f(foo<int>::bar);

int main() {}