#include <vector>
using namespace std;

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(begin(seats),end(seats));
        sort(begin(students),end(students));
        int tot = 0;
        for(int i=0;i<seats.size();i++) tot+=abs(seats[i]-students[i]);
        return tot;
    }
};