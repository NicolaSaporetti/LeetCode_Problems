using namespace std;
#include <cassert>
#include <iostream>

template<typename T>
class wrapper
{
    public:
    wrapper(T const v) : value(v) {}
    T value;
};

template<typename T>
class wrapper_v2
{
public:
    wrapper_v2(T const v) : value(v) {}
    T const& get() const {return value;}
    template<typename U>
    U as() const
    {
        return static_cast<U>(value);
    }
private:
    T value;
};

template<typename T, typename U, template<typename> typename W = wrapper_v2>
class wrapper_pair
{
public:
    wrapper_pair(T const a, U const b) : item1(a), item2(b) {}
    W<T> item1;
    W<U> item2;
};

int main()
{
    wrapper<int> w(4);
    wrapper_v2<float> w2(2.5);
    cout<<w.value<<endl;
    cout<<w2.get()<<" "<<w2.as<int>()<<endl;
    wrapper_pair pair_v2(10,3.34);
    cout<<pair_v2.item1.get()<<" "<<pair_v2.item2.get()<<endl;
    wrapper_pair<int,double,wrapper> pair_v1(5,1.67);
    cout<<pair_v1.item1.value<<" "<<pair_v1.item2.value<<endl;
}