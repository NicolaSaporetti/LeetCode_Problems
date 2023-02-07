#include <map>
#include <vector>
using namespace std;

class StockPrice {
public:
    StockPrice() {}
    
    void update(int timestamp, int price) {
        if(m.count(timestamp)!=0)
        {
            int prevP = m[timestamp];
            values[prevP]--;
            if(values[prevP]==0) values.erase(prevP);
        }
        m[timestamp]=price;
        values[price]++;
    }
    
    int current() {
        return m.rbegin()->second;
    }
    
    int maximum() {
        return values.rbegin()->first;
    }
    
    int minimum() {
        return values.begin()->first;
    }
    map<int,int> m;
    map<int,int> values;
};