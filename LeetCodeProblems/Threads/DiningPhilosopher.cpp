#include <array>
#include <mutex>
using namespace std;

class DiningPhilosophers {
public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
		scoped_lock sl(v[philosopher],v[(philosopher+1)%5]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
private:
    array<mutex,5> v;
};