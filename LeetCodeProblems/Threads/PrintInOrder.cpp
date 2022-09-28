#include <vector>
#include <mutex>
#include <condition_variable>
#include <iostream>
using namespace std;

class Foo {
public:
    Foo() {
        counter = 1;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        unique_lock<mutex> lck(mtx);
        printFirst();
        counter=2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        unique_lock<mutex> lck(mtx);
        while (counter!=2) cv.wait(lck);
        printSecond();
        counter=3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        unique_lock<mutex> lck(mtx);
        while (counter!=3) cv.wait(lck);
        printThird();
    }
private:
    int counter;
    condition_variable cv;
    mutex mtx;
};