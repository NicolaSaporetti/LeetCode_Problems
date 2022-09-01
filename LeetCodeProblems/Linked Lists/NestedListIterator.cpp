#include <iostream>
#include <vector>
using namespace std;

class NestedIterator {
private: 
    vector<int> list;
    int current = 0;
    void extractVector(const vector<NestedInteger>& nestedList)
    {
        for(int i=0;i<nestedList.size();i++)
        {
            if(nestedList[i].isInteger())
            {
                list.push_back(nestedList[i].getInteger());
            }
            else 
            {
                extractVector(nestedList[i].getList());
            }
        }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        extractVector(nestedList);
    }
    
    int next() {
        return list[current++];
    }
    
    bool hasNext() {
        return current!=(list.size());
    }
};