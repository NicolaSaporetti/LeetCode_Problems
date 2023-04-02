using namespace std;
#include <iostream>

template<typename... Args>
int sum(Args... args)
{
    return (...+args);
};

template<typename T>
T step_it(T value)
{
    return value+1;
};

template<typename... Args>
void do_sums(Args... args)
{
    cout<<sum(args...)<<endl;
    cout<<sum(42,args...)<<endl;
    cout<<sum(step_it(args)...)<<endl;
};

int main()
{
    do_sums(1,2,3,4);
}