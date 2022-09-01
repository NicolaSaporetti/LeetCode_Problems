#include <iostream>
#include <priority_queue>
using namespace std;

class SeatManager {
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++) pq.push(i);
    }
    
    int reserve() {
        int v = pq.top();
        pq.pop();
        return v;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
};