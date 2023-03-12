#include <mutex>
#include <condition_variable>
using namespace std;

class Foo {
public:
    Foo() : status(0) {}

    void first(function<void()> printFirst) {
        unique_lock<mutex> ul(m);
        printFirst();
        status++;
        ul.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> ul(m);
        cv.wait(ul,[=](){return status==1;});
        printSecond();
        status++;
        ul.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> ul(m);
        cv.wait(ul,[=](){return status==2;});
        status++;
        printThird();
    }
private:
    int status;
    mutex m;
    condition_variable cv;
};