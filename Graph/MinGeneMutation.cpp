#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        visited.resize(bank.size());
        for(int i=0;i<visited.size();i++) visited[i]=false;
        if(computeDistance(start,end)==0) return 0;
        else if(!endPositionIsInBank(end,bank)) return -1;
        else
        {
            addElem(start,bank);
            return computeMinMutation(end,bank);
        }
    }

private:
    bool endPositionIsInBank(string& s, vector<string>& bank)
    {
        for(int i=0;i<bank.size();i++) if(s.compare(bank[i])==0) return true;
        return false;
    }
    
    int computeMinMutation(string& end, vector<string>& bank)
    {
        int distance = 0;
        while(!wordToEvaluate.empty())
        {
            distance ++;
            int num = wordToEvaluate.size();
            for(int i=0;i<num;i++)
            {
                int elem = wordToEvaluate.front();
                wordToEvaluate.pop();
                if(computeDistance(end,bank[elem])==0) return distance;
                else
                {
                    addElem(bank[elem],bank);
                }
            }
        }
        return -1;
    }
    
    void addElem(string& origin, vector<string>& bank)
    {
        for(int i=0;i<bank.size();i++)
        {
            if(!visited[i] && computeDistance(origin,bank[i])==1)
            {
                wordToEvaluate.push(i);
                visited[i] = true;
            }
        }
    }
    
    int computeDistance(string& origin, string& dest)
    {
        int res = 0;
        for(int i=0;i<origin.size();i++)
        {
            if(origin[i]!=dest[i]) res++;
        }
        return res;
    }
    queue<int> wordToEvaluate;
    vector<bool> visited;
};