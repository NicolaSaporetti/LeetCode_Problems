#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    set<int> minimums;
    int sz;
    
    int computeSinglePointEnd(int elem)
    {
        int result = 0;
        int value = 2;
        for(int i=elem+1;i<sz;i++)
        {
            result+=value;
            value++;
        }
        return result;
    }
    
    int computeSinglePointStart(int elem)
    {
        int result = 0;
        int value = 2;
        for(int i=elem-1;i>=0;i--)
        {
            result+=value;
            value++;
        }
        return result;
    }
    
    int computeDoublePoint(int start, int end, vector<int>& ratings)
    {
        int result = 0;
        int valueStart = 2;
        int valueEnd = 2;
        while(start+2<end && ratings[start]<ratings[start+1] && ratings[start+1]<ratings[start+2])
        {
            result+=valueStart;
            valueStart++;
            start++;
        }
        while(start<end-2 && ratings[end-1]>ratings[end] && ratings[end-2]>ratings[end-1])
        {
            result+=valueEnd;
            valueEnd++;
            end--;
        }
        if(start+2==end)
        {
            result+=(max(valueStart,valueEnd));
        }
        else
        {
            result+=(valueStart+valueEnd);
        }
        return result;
    }
public:
    int candy(vector<int>& ratings) {
        sz = ratings.size();
        int result = 0;
        for(int i=1;i<sz-1;i++)
        {
            if(((ratings[i]<ratings[i-1] && ratings[i]<ratings[i+1])) ||
                (ratings[i]==ratings[i-1] && ratings[i+1]>=ratings[i]) ||
                (ratings[i]<=ratings[i-1] && ratings[i+1]==ratings[i]))
            {
                minimums.insert(i);
            }
        }
        if(sz>=2)
        {
            if(ratings[0]<=ratings[1]) minimums.insert(0);
            if(ratings[sz-1]<=ratings[sz-2]) minimums.insert(sz-1);
        }
        if(minimums.size()==0) return 1;
        else if(minimums.size()==1)
        {
            auto it = minimums.begin();
            result++;
            result+=computeSinglePointStart(*it);
            result+=computeSinglePointEnd(*it);
        }
        else
        {
            result+=minimums.size();
            auto first = minimums.begin();
            result+=computeSinglePointStart(*first);
            auto second = minimums.begin();
            second++;
            for(;second!=minimums.end();second++,first++)
            {
                if(*first+1<*second) result+=computeDoublePoint(*first,*second, ratings);
            }
            result+=computeSinglePointEnd(*first);
        }
        return result;
    }
};