#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
private:
    set<int> keys;
    set<int> roomsToVisit;
    
    void addkeys(int room, vector<vector<int>>& rooms)
    {
        for(int i=0;i<rooms[room].size();i++)
        {
            int key = rooms[room][i];
            if(roomsToVisit.find(key)!=roomsToVisit.end())
            {
                keys.insert(key);
            }
        }
        roomsToVisit.erase(room);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        for(int i=0;i<rooms.size();i++)
        {
            roomsToVisit.insert(i);
        }
        addkeys(0,rooms);
        auto it = keys.begin();
        while(!keys.empty())
        {
            if(it==keys.end()) it = keys.begin();
            int key = *it;
            addkeys(key,rooms);
            it = keys.erase(it);
        }
        return (roomsToVisit.empty())? true : false;
    }
};