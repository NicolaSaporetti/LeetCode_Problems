#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> pos;
        int sz = arr.size();
        vector<int> visited(sz,false);
        pos.push(start);
        visited[start]=true;
        while(!pos.empty())
        {
            int elem = pos.front();
            pos.pop();
            if(arr[elem] == 0) return true;
            int newElem = elem + arr[elem];
            if(newElem<sz && !visited[newElem])
            {
                pos.push(newElem);
                visited[newElem] = true;
            }
            newElem = elem - arr[elem];
            if(newElem>=0 && !visited[newElem])
            {
                pos.push(newElem);
                visited[newElem] = true;
            }
        }
        return false;
    }
};