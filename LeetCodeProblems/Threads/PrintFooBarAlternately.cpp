#include <mutex>
#include <condition_variable>
using namespace std;

class FooBar {
private:
    int n;
    condition_variable cv;
    mutex mtx;
    bool isFooPrinted;

public:
    FooBar(int n) {
        this->n = n;
        isFooPrinted = false;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            if(isFooPrinted) cv.wait(lck);
        	printFoo();
            isFooPrinted = true;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lck(mtx);
            if(!isFooPrinted) cv.wait(lck);
        	printBar();
            isFooPrinted = false;
            cv.notify_one();
        }
    }
};