#include <thread>
#include <vector>
#include <mutex>
using namespace std;

class H2O {
public:
    H2O() {
        H=2;
        O=1;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(mtx);
        while(H==0) cv.wait(lck);
        releaseHydrogen();
        H--;
        if(H==0 && O==0)
        {
            H=2;
            O=1;
        }
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(mtx);
        while(O==0) cv.wait(lck);
        releaseOxygen();
        O--;
        if(H==0 && O==0)
        {
            H=2;
            O=1;
        }
        cv.notify_one();
    }
private:
    int H;
    int O;
    mutex mtx;
    condition_variable cv;
};