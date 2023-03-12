#include <iostream>           // std::cout
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <queue>
using namespace std;

mutex mtx;
condition_variable cv;
queue<int> myQ;
bool finish;

void consume() {
  do
  {
    unique_lock<mutex> lck(mtx);
    cv.wait(lck,[](){return !myQ.empty();});
    while(!myQ.empty())
    {
        std::cout << "Consumer Thread, queue element: " << myQ.front() << " size: " << myQ.size() << std::endl;
        myQ.pop();
    }
  } while(!finish);
}

void produce() {
  for(int i=0;i<1000;i++)
  {
    {
      unique_lock<mutex> lck(mtx);
      std::cout << "Producer Thread, queue size: " << myQ.size() << std::endl;
      bool notificationNeeded = myQ.empty();
      myQ.push(i);
      lck.unlock();
      if(notificationNeeded) cv.notify_one();
    }
  }
  finish = true;
}

int main ()
{
  finish = false;
  thread t1(produce);
  thread t2(consume);
  t1.join();
  t2.join();
  return 0;
}
