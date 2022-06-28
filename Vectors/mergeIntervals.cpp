#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Solution {
private:
    list<int> mylist;

    void mergeElement(vector<int>& interval)
    {
        list<int>::iterator it = mylist.begin();
        bool intervalIsIncluded = true;
        while(it != mylist.end() && *it<interval[0])
        {
            ++it;
            intervalIsIncluded = !intervalIsIncluded;
        }
        if(it == mylist.end())  //end of the list
        {
            mylist.insert(it,interval[0]);
            mylist.insert(it,interval[1]);
        }
        else
        {
            if(*it==interval[0])
            {
                if(intervalIsIncluded)
                {
                    ++it;
                    intervalIsIncluded = !intervalIsIncluded;
                }
                else{
                    it=mylist.erase(it);
                    intervalIsIncluded = !intervalIsIncluded;
                }
            }
            else
            {
                if(intervalIsIncluded)
                {
                    mylist.insert(it,interval[0]);
                }
            }

            //try set the second part
            while(it != mylist.end() && *it<interval[1])
            {
                it=mylist.erase(it);
                intervalIsIncluded = !intervalIsIncluded;
            }
            if(it == mylist.end())
            {
                mylist.insert(it,interval[1]);
                intervalIsIncluded = !intervalIsIncluded;
            }
            else{
                if(*it==interval[1])
                {
                    if(intervalIsIncluded)
                    {
                        it=mylist.erase(it);
                        intervalIsIncluded = !intervalIsIncluded;
                    }
                }
                else
                {
                    if(intervalIsIncluded)
                    {
                        mylist.insert(it,interval[1]);
                        intervalIsIncluded = !intervalIsIncluded;
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> sol;
        for(int i=0;i<intervals.size();i++)
        {
            vector<int>& interval=intervals[i];
            mergeElement(interval);
            for(auto it = mylist.begin(); it != mylist.end(); ++it) cout<<*it<<endl;
        }
        bool intervalIsIncluded = true;
        vector<int> set;
        set.resize(2);
        for(auto it = mylist.begin(); it != mylist.end(); ++it)
        {
            if(intervalIsIncluded)
            {
                set[0]=*it;
                intervalIsIncluded = !intervalIsIncluded;
            }
            else{
                set[1]=*it;
                sol.push_back(set);
                intervalIsIncluded = !intervalIsIncluded;
            }
        }
        return sol;
    }
};