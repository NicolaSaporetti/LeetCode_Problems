#ifndef Financial_HPP
#define Financial_HPP
#include <vector>
using namespace std;

class Financial {
public:
    void simplifyGraph(vector<int>& prices);

private:
    void simplifyBear(vector<int>& prices);
    void simplifyBull(vector<int>& prices);
    void translateValuesToRelative(vector<int>& prices);
};
#endif