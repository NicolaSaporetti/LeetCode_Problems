#include <condition_variable>
#include <mutex>
using namespace std;

class H2O {
public:
    H2O() {
        resetMolecule();
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul,[=](){return h>0;});
        releaseHydrogen();
        h--;
        if(moleculeIsFormed()) resetMolecule();
        ul.unlock();
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul,[=](){return o>0;});
        releaseOxygen();
        o--;
        if(moleculeIsFormed()) resetMolecule();
        ul.unlock();
        cv.notify_one();
    }

private:
    bool moleculeIsFormed()
    {
        return o==0 && h==0;
    }

    void resetMolecule()
    {
        o=1;
        h=2;
    }

    int o;
    int h;
    condition_variable cv;
    mutex m;
};