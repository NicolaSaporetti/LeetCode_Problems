#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        visited.resize(10000);
        for(int i=0;i<visited.size();i++) visited[i]=false;
        for(int i=0;i<deadends.size();i++) blockedCombinations.insert(deadends[i]);
        
        addElem("0000");
        return computeMinSteps(target);
    }

private:
    int computeMinSteps(string target)
    {
        int distance = 0;
        while(!paths.empty())
        {
            int num = paths.size();
            for(int i=0;i<num;i++)
            {
                string elem = paths.front();
                paths.pop();
                if(!target.compare(elem)) return distance;
                else
                {
                    for(int i=0;i<4;i++) computeNext(i,elem);
                }
            }
            distance ++;
        }
        return -1;
    }
    
    void addElem(string elem)
    {
        if(blockedCombinations.find(elem)==blockedCombinations.end() && !visited[stoi(elem)])
        {
            paths.push(elem);
            visited[stoi(elem)] = true;
        }
    }

    void computeNext(int digit, string elem)
    {
        string temp = elem;
        (temp[digit]!='0')? temp[digit]-- : temp[digit] ='9';
        addElem(temp);
        
        temp = elem;
        (temp[digit]!='9')? temp[digit]++ : temp[digit] ='0';
        addElem(temp);
        temp = elem;
    }
    
    queue<string> paths;
    vector<bool> visited;
    set<string> blockedCombinations;
};