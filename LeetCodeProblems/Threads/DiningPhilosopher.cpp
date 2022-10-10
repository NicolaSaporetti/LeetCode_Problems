#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        resources.assign(5,1);
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        unique_lock<mutex> lck(m);
        if(resources[philosopher]==1 && resources[(philosopher+1)%5]==1)
        {
            resources[philosopher]=0;
            resources[(philosopher+1)%5]=0;
        }
        else cv.wait(lck);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
        resources[philosopher]=1;
        resources[(philosopher+1)%5]=1;
        cv.notify_all();
		
    }
private:
    mutex m;
    condition_variable cv;
    vector<int> resources;
};