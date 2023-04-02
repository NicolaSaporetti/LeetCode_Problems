#include <iostream>
#include <vector>
using namespace std;

template<typename T,typename... Args>
void push_back_many(vector<T>& v, Args&&... args)
{
    (v.push_back(args),...);
}

template<typename T,typename... Args>
void push_back_manyl(vector<T>& v, Args&&... args)
{
    (...,v.push_back(args));
}

int main()
{
    vector<int> v;
    push_back_many(v,1,2,3,4,5,6,7);
    for(auto& e : v) cout<<e<<" ";
    cout<<endl;
    v.clear();
    push_back_manyl(v,1,2,3,4,5,6,7);
    for(auto& e : v) cout<<e<<" ";
}