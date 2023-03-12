#include <mutex>
#include <condition_variable>
using namespace std;

class FizzBuzz {
public:
    FizzBuzz(int n) : n(n), current(1) {}

    void fizz(function<void()> printFizz) {
        while(current<=n)
        {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return current>n || (current%3==0 && current%5!=0);});
            if(current<=n)
            {
                printFizz();
                current++;
            }
            ul.unlock();
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while(current<=n)
        {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return current>n || (current%5==0 && current%3!=0);});
            if(current<=n)
            {
                printBuzz();
                current++;
            }
            ul.unlock();
            cv.notify_all();
        }
    }

	void fizzbuzz(function<void()> printFizzBuzz) {
        while(current<=n)
        {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return current>n || (current%3==0 && current%5==0);});
            if(current<=n)
            {
                printFizzBuzz();
                current++;
            }
            ul.unlock();
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while(current<=n)
        {
            unique_lock<mutex> ul(m);
            cv.wait(ul,[=](){return current>n || (current%3!=0 && current%5!=0);});
            if(current<=n)
            {
                printNumber(current);
                current++;
            }
            ul.unlock();
            cv.notify_all();
        }
    }
private:
    int n;
    int current;
    mutex m;
    condition_variable cv;
};