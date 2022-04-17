#include <iostream>
#include <stdlib.h>
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
            cout<<"Interval open: "<<intervalIsIncluded<<endl;
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
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                    cout<<"Same entry point"<<endl;
                    ++it;
                }
                else{
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                    cout<<"initial stop the boundar, expand it"<<endl;
                    it=mylist.erase(it);
                    intervalIsIncluded = !intervalIsIncluded;
                }
            }
            else
            {
                if(intervalIsIncluded)
                {
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                    cout<<"new set to create"<<endl;
                    mylist.insert(it,interval[0]);
                    intervalIsIncluded = !intervalIsIncluded;
                }
                else{
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                    cout<<"inside a set skip"<<endl;
                }
            }

            cout<<"Second part"<<endl;
            //try set the second part
            while(it != mylist.end() && *it<interval[1])
            {
                cout<<"Interval open: "<<intervalIsIncluded<<endl;
                cout<<"Remove element"<<endl;
                it=mylist.erase(it);
                intervalIsIncluded = !intervalIsIncluded;
            }
            if(it == mylist.end())
            {
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                cout<<"end list"<<endl;
                mylist.insert(it,interval[1]);
                intervalIsIncluded = !intervalIsIncluded;
            }
            else{
                if(*it==interval[1])
                {
                    if(intervalIsIncluded)
                    {
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                        cout<<"exit is the same do nothing"<<endl;
                    }
                    else{
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                        cout<<"initial start new set"<<endl;
                        it=mylist.erase(it);
                        intervalIsIncluded = !intervalIsIncluded;
                    }
                }
                else
                {
                    if(intervalIsIncluded)
                    {
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                        cout<<"create a new ending"<<endl;
                        mylist.insert(it,interval[1]);
                        intervalIsIncluded = !intervalIsIncluded;
                    }
                    else{
                    cout<<"Interval open: "<<intervalIsIncluded<<endl;
                        cout<<"initial inside the boundaries, do nothing"<<endl;
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
            cout<<"List"<<endl;
            for(auto it = mylist.begin(); it != mylist.end(); ++it) cout<<*it<<endl;
        }
        bool intervalIsIncluded = true;
        vector<int> set;
        set.resize(2);
        for(auto it = mylist.begin(); it != mylist.end(); ++it)
        {
            if(intervalIsIncluded)
            {
                cout<<"Addint starting item: "<<*it<<endl;
                set[0]=*it;
                intervalIsIncluded = !intervalIsIncluded;
            }
            else{
                cout<<"Addint ending item: "<<*it<<endl;
                set[1]=*it;
                sol.push_back(set);
                intervalIsIncluded = !intervalIsIncluded;
            }
        }
        return sol;
    }
};

int main()
{
    vector<vector<int>> now = {{0,2},{1,4}};
    //vector<vector<int>> now = {{1,4},{1,4}};
    //vector<vector<int>> now = {{1,4},{2,3}};
    //vector<vector<int>> now = {{1,4},{5,6}};
    Solution solution;
    vector<vector<int>> sol = solution.merge(now);
    for(vector<int> i: sol)
    {
        cout<<i[0]<<" "<<i[1]<<endl;
    }
    return 0;
}