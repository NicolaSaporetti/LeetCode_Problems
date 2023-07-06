#include <set>
using namespace std;

class SeatManager {
public:
    SeatManager(int n) {
        for(int i=0;i<n;i++) unres.insert(i+1);
    }
    
    int reserve() {
        auto it =unres.begin();
        res.insert(*it);
        int val = *it;
        unres.erase(*it);
        return val;
    }
    
    void unreserve(int seatNumber) {
        unres.insert(seatNumber);
        res.erase(seatNumber);
    }
    
    set<int> res;
    set<int> unres;
};