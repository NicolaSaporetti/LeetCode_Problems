#include <stack>
using namespace std;

class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int num = 1;
        while(!s.empty() && s.top().first<=price)
        {
            num+=s.top().second;
            s.pop();
        }
        s.push({price,num});
        return num;
    }
private:
    stack<pair<int,int>> s;
};