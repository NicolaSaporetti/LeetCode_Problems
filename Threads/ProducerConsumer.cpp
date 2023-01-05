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

    while (myQ.empty())
    {
        cv.wait(lck); // predicate an while loop - protection from spurious wakeups
    }
    while(!myQ.empty()) // consume all elements from queue
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
  cout<<myQ.empty()<<endl;

  return 0;
}
