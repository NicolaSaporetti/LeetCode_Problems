#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    int findSet(vector<vector<int>>& intervals, int value)
    {
        int element = intervals.size()-1;
        for(int i=0;i<intervals.size();i++)
        {
            if(value<=intervals[i][0] || value<=intervals[i][1])
            {
                element =i;
                break;
            }
        }
        return element;
    }
    
    void add(vector<vector<int>>& intervals, int start, int finish, vector<vector<int>>& result)
    {
        for(int i=start;i<=finish;i++)
        {
            result.push_back(intervals[i]);
        } 
    }
    
    void mergeIntervals(vector<vector<int>>& intervals, vector<int>& newInterval, int firstElem, int secondElem, vector<vector<int>>& result)
    {
        vector<int> elemToMerge = {newInterval[0], newInterval[1]};
        if(newInterval[0]<=intervals[secondElem][1])
        {
            elemToMerge[0]= min(intervals[firstElem][0],newInterval[0]);
            if(intervals[secondElem][1]>newInterval[1] && intervals[secondElem][0]>newInterval[1])
            {
                elemToMerge[1]=newInterval[1]; 
            }
            else
            {
                elemToMerge[1]=max(intervals[secondElem][1],newInterval[1]);
            }
        }
        else
        {
            result.push_back(intervals[secondElem]);
        }
        result.push_back(elemToMerge);
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        if(intervals.size()==0)
        {
            vector<int> elem = {newInterval[0], newInterval[1]};
            result.push_back(elem);
        }
        else
        {
            int firstElem = findSet(intervals,newInterval[0]);
            int secondElem = findSet(intervals,newInterval[1]);
            if(firstElem>0) add(intervals,0,firstElem-1,result);
            mergeIntervals(intervals,newInterval,firstElem,secondElem,result);
            if(intervals[secondElem][0]>newInterval[1]) add(intervals,secondElem, secondElem,result);
            if(secondElem<intervals.size()-1) add(intervals,secondElem+1, intervals.size()-1,result);
        }
        return result;
    }
};

int main()
{
    Solution solution;
    return 0;
}