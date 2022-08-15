#include <iostream>
#include <list>
using namespace std;

class MyLinkedList {
private:
    list<int> myList;
public:
    MyLinkedList() {
    }
    
    int get(int index) {
        int i=0;
        for(auto it=myList.begin();it!=myList.end();it++,i++)
        {
            if(i==index)
            {
                return *it;
                break;
            }
        }
        return -1;
    }
    
    void addAtHead(int val) {
        myList.push_front(val);
    }
    
    void addAtTail(int val) {
        myList.push_back(val);
    }
    
    void addAtIndex(int index, int val) {
        if(myList.size()==index) myList.push_back(val);
        else if(index<myList.size())
        {
            int i=0;
            for(auto it=myList.begin();it!=myList.end();it++,i++)
            {
                if(i==index)
                {
                    myList.insert(it,val);
                    break;
                }
            }
        }
    }
    
    void deleteAtIndex(int index) {
        int i=0;
        for(auto it=myList.begin();it!=myList.end();it++,i++)
        {
            if(i==index)
            {
                myList.erase(it);
                break;
            }
        }
    }
};