#include <iostream>
#include <map>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        auto itr = mp.upper_bound(start);
        if(itr == mp.end() || end<= itr->second) {
            mp[end]=start;
            return true;
        } 
        else  return false;
    }
private:
    map<int,int> mp;
};