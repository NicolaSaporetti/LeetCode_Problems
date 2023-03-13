using namespace std;
#include <iostream>

template<typename inpV, typename outV = Vector<>>
struct uniq;

template<int i, int... tail, int... outTail>
struct uniq<Vector<i,i,tail...>, Vector<outTail...>>
{

};

int main()
{
    vector<int> original_0 = {2,2,3,4,5,5,5,5,6,6};
    vector<int> result_0 = {2,3,4,5,6};
    vector<int> original_1 = {1};
    vector<int> result_1 = {1};
    vector<int> original_2 = {1,2,1,2};
    vector<int> result_2 = {1,2,1,2};
    vector<int> original_3 = {1,1,1,1,2,2,2,2,2,1,2,2,2,2,2,2};
    vector<int> result_3 = {1,2,1,2};
    assert(removeDuplicate(),true);
}