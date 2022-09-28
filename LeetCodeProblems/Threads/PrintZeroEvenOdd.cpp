#include <vector>
#include <mutex>
#include <condition_variable>
#include <iostream>
using namespace std;

class ZeroEvenOdd {
private:
    int n;
    mutex mtx;
    int code;
    bool zeroPrinted;
    int number;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        code = 1;
        number = 1;
        zeroPrinted = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;i++)
        {
            unique_lock<mutex> lck(mtx);
            while(zeroPrinted) cv.wait(lck);
            printNumber(0);
            zeroPrinted = true;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for(int i=0;i<n/2;i++)
        {
            unique_lock<mutex> lck(mtx);
            while(!zeroPrinted || code%2==1) cv.wait(lck);
            printNumber(code);
            code++;
            zeroPrinted = false;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=0;i<(n+1)/2;i++)
        {
            unique_lock<mutex> lck(mtx);
            while(!zeroPrinted || code%2==0) cv.wait(lck);
            printNumber(code);
            code++;
            zeroPrinted = false;
            cv.notify_all();
        }
    }
};