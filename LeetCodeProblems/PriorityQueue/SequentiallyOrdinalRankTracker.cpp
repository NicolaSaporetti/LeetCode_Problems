#include <priority_queue>
using namespace std;

class SORTracker {
public:
    int curr = 0;
    priority_queue<pair<int, string>> maxHeap;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> minHeap;
    SORTracker() {}
    
    void add(string name, int score) {
        minHeap.push({-score, name});
    }
    
    string get() {
        curr++;
        while(maxHeap.size() < curr) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if(!minHeap.empty()) {
            while((-maxHeap.top().first < -minHeap.top().first) || (maxHeap.top().first == minHeap.top().first && maxHeap.top().second > minHeap.top().second)) {
                auto temp = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(temp);
            }
        }
        return maxHeap.top().second;
    }
};