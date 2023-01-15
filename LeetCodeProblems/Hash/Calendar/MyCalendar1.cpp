#include <map>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        mp[start]++, mp[end]--;
        int curr = 0;
        bool ans = true;
        
        for(auto &i : mp)
        {
            curr += i.second;
            if(curr>1)
            {
                mp[start]--, mp[end]++;
                ans = false;
                break;
            }
        }
        
        return ans;
    }
private:
    map<int,int> mp;
};