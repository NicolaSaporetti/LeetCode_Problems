#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        sz = k;
        queue.resize(sz,0);
        front = 0;
        back = sz-1;
        queueIsEmpty = true;
    }
    
    bool enQueue(int value) {
        if(!isFull())
        {
            back=(back+1)%sz;
            queue[back]=value;
            if(queueIsEmpty) queueIsEmpty = false;
            return true;
        }
        else return false;
    }
    
    bool deQueue() {
        if(!isEmpty())
        {
            front=(front+1)%sz;
            if((back+1)%sz == front) queueIsEmpty = true;
            return true;
        }
        else return false;
    }
    
    int Front() {
        if(!isEmpty()) return queue[front];
        else return -1;
    }
    
    int Rear() {
        if(!isEmpty()) return queue[back];
        else return -1;
    }
    
    bool isEmpty() {
        return queueIsEmpty;
    }
    
    bool isFull() {
        return (!queueIsEmpty && front == ((back+1)%sz));
    }
private:
    vector<int> queue;
    int front;
    int back;
    int sz;
    bool queueIsEmpty;
};