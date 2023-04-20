#include <iostream>
#include <vector>
#include <map>
using namespace std;

class SnapshotArray {
    vector<map<int, int>> snaps;
    int snapId = 0;
    
public:
    SnapshotArray(int length) {
        snaps.resize(length, {{0, 0}});
    }
    
    void set(int index, int val) {
        snaps[index][snapId] = val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        return prev(snaps[index].upper_bound(snap_id))->second;
    }
};