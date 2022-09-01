#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0)
        {
            result.push_back(newInterval);
        }
        else
        {
            int firstElem = findSet(intervals,newInterval[0]);
            int secondElem = findSet(intervals,newInterval[1]);
            add(intervals,0,firstElem-1);
            mergeIntervals(intervals,newInterval,firstElem,secondElem);
            add(intervals,secondElem+1, intervals.size()-1);
        }
        return result;
    }
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
    
    void add(vector<vector<int>>& intervals, int start, int finish)
    {
        for(int i=start;i<=finish;i++)
        {
            result.push_back(intervals[i]);
        } 
    }
    
    void mergeIntervals(vector<vector<int>>& intervals, vector<int>& newInterval, int firstElem, int secondElem)
    {
        if(newInterval[0]<=intervals[secondElem][1])
        {
            newInterval[0]= min(intervals[firstElem][0],newInterval[0]);
            if(!(intervals[secondElem][1]>newInterval[1] && intervals[secondElem][0]>newInterval[1]))
            {
                newInterval[1]=max(intervals[secondElem][1],newInterval[1]);
            }
        }
        else
        {
            result.push_back(intervals[secondElem]);
        }
        result.push_back(newInterval);
        if(intervals[secondElem][0]>newInterval[1]) add(intervals,secondElem, secondElem);
    }
    
    vector<vector<int>> result;
};