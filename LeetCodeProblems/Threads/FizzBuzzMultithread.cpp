#include <mutex>
#include <condition_variable>
#include <iostream>
using namespace std;

class FizzBuzz {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    int value;

public:
    FizzBuzz(int n) {
        this->n = n;
        value = 1;
    }

    void fizz(function<void()> printFizz) {
        while(value<=n)
        {
            unique_lock<mutex> lck(mtx);
            while(!(value%3==0 && value%15!=0) && value<=n)
            {
                cv.wait(lck);
            }
            if(value>n) return;
            printFizz();
            value++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while(value<=n)
        {
            unique_lock<mutex> lck(mtx);
            while(!(value%5==0 && value%15!=0) && value<=n)
            {
                cv.wait(lck);
            }
            if(value>n) return;
            printBuzz();
            value++;
            cv.notify_all();
        }
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        while(value<=n)
        {
            unique_lock<mutex> lck(mtx);
            while(!(value%15==0) && value<=n)
            {
                cv.wait(lck);
            }
            if(value>n) return;
            printFizzBuzz();
            value++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while(value<=n)
        {
            unique_lock<mutex> lck(mtx);
            while((value%3==0 || value%5==0) && value<=n)
            {
                cv.wait(lck);
            }
            if(value>n) return;
            printNumber(value);
            value++;
            cv.notify_all();
        }
    }
};