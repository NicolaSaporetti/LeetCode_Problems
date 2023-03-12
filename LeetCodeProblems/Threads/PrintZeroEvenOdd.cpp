#include <mutex>
#include <condition_variable>
using namespace std;

class ZeroEvenOdd {
public:
    ZeroEvenOdd(int n) : n(n), isZeroPosition(true), current(1) {
    }

    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;i++)
        {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return isZeroPosition;});
            printNumber(0);
            isZeroPosition=!isZeroPosition;
            cv.notify_all();
            ul.unlock();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=0;i<n/2;i++)
        {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return !isZeroPosition && current%2==0;});
            printNumber(current++);
            isZeroPosition=!isZeroPosition;
            cv.notify_all();
            ul.unlock();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=0;i<(n+1)/2;i++)
        {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return !isZeroPosition && current%2==1;});
            printNumber(current++);
            isZeroPosition=!isZeroPosition;
            cv.notify_all();
            ul.unlock();
        }
    }
private:
    int n;
    bool isZeroPosition;
    int current;
    condition_variable cv;
    mutex m;
};