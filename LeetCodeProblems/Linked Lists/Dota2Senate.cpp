#include <list>
#include <vector>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        rad = 0;
        dir = 0;
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i]=='R')
            {
                senators.push_back('R');
                rad++;
            }
            else
            {
                senators.push_back('D');
                dir++;
            }
        }
        removeSenators();
        return (rad)? "Radiant" : "Dire";
    }
private:
    void removeSenators()
    {
        int dir_to_remove = 0;
        int rad_to_remove = 0;
        auto it = senators.begin();
        while(rad>0 && dir>0)
        {
            if(*it=='R')
            {
                if(rad_to_remove>0)
                {
                    senators.erase(it++);
                    rad_to_remove--;
                    rad--;
                }
                else
                {
                    dir_to_remove++;
                    it++;
                }
            }
            else
            {
                if(dir_to_remove>0)
                {
                    senators.erase(it++);
                    dir_to_remove--;
                    dir--;
                }
                else
                {
                    rad_to_remove++;
                    it++;
                }
            }
            if(it==senators.end()) it=senators.begin();
        }
    }

    list<char> senators;
    int rad;
    int dir;
};