using namespace std;

template<typename T>
struct foo {};

template<>
struct foo<int>;

int main()
{
    foo<double> a;
    foo<int>* b;
    //foo<int> c;
}