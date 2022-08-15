#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        visited.resize(jug1Capacity+jug2Capacity+1);
        for(int i=0;i<=jug1Capacity+jug2Capacity;i++) visited[i]=false;
        addCombination(0);
        if(jug1Capacity+jug2Capacity<targetCapacity) return false;
        else return performJugOperations(jug1Capacity,jug2Capacity,targetCapacity);
    }
private:
    bool performJugOperations(int jug1Cap, int jug2Cap, int targetCap)
    {
        while(!combinations.empty())
        {
            int elem = combinations.front();
            combinations.pop();
            if(elem==targetCap) return true;
            else {
                if(elem+jug1Cap<=jug1Cap+jug2Cap && !visited[elem+jug1Cap]) addCombination(elem+jug1Cap);
                if(elem+jug2Cap<=jug1Cap+jug2Cap && !visited[elem+jug2Cap]) addCombination(elem+jug2Cap);
                if(elem-jug1Cap>=0 && !visited[elem-jug1Cap]) addCombination(elem-jug1Cap);
                if(elem-jug2Cap>=0 && !visited[elem-jug2Cap]) addCombination(elem-jug2Cap);
            }
        }
        return false;
    }
               
   void addCombination(int jug)
   {
       combinations.push(jug);
       visited[jug]=true;
   }
    
    queue<int> combinations;
    vector<int> visited;
};