using namespace std;
template<class T>
class A
{
public:
    T a;
    T b;
    A(T a, T b) : a(a), b(b) {}

    T get_sum();
};

template<class T>
T A<T>::get_sum()
{
    return a+b;
}

int main()
{
    A<int> myClass(4,5);
    int a = myClass.get_sum();
    cout<<a<<endl;
}