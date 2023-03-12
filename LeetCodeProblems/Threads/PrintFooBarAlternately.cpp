#include <mutex>
#include <condition_variable>
using namespace std;

class FooBar {
public:
    FooBar(int n) : n(n), isFoo(true) {}

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return isFoo;});
        	printFoo();
            isFoo = !isFoo;
            ul.unlock();
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return !isFoo;});
        	printBar();
            isFoo = !isFoo;
            ul.unlock();
            cv.notify_one();
        }
    }
private:
    int n;
    bool isFoo;
    condition_variable cv;
    mutex m;
};