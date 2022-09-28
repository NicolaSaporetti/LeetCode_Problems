#include <atomic>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex mtx;
int var;

void print_block (int n) {
  for (int i=0; i<n; ++i)
  {
    if(mtx.try_lock())
    {
      var++;
      mtx.unlock();
    }
  }
}

int main ()
{
  var =0;
  vector<thread> v1;
  for(int i=0;i<10;i++)
  {
    v1.push_back(thread(print_block,10000));
  }
  for(int i=0;i<v1.size();i++)
  {
    v1[i].join();
  }

  return 0;
}