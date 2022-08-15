#ifndef Financial_HPP
#define Financial_HPP
#include <vector>
using namespace std;

class Financial {
public:
    void simplifyBear(vector<int>& prices);
    void simplifyBull(vector<int>& prices);
    void translateValuesToRelative(vector<int>& prices);
    int computeProfit(vector<int>& relative_prices);
};
#endif