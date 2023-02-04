#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> notes(2,0);
        for(auto& bill : bills)
        {
            if(bill==5) notes[0]++;
            else if(bill==10)
            {
                if(notes[0]==0) return false;
                else
                {
                    notes[0]--;
                    notes[1]++;
                }
            }
            else
            {
                if(notes[1]>0 && notes[0]>0)
                {
                    notes[1]--;
                    notes[0]--;
                }
                else if(notes[1]==0 && notes[0]>=3) notes[0]-=3;
                else return false;
            }
        }
        return true;
    }
};