#include <atomic>
#include <thread>
#include <vector>
#include <iostream>
using namespace std;

atomic<int> global_counter (0);

void increase_global  (int n) { for (int i=0; i<n; ++i) ++global_counter; }

void increase_reference (atomic<int>& variable, int n) { for (int i=0; i<n; ++i) ++variable; }

int main ()
{
  vector<thread> threads;

  cout << "increase global counter with 10 threads...\n";
  for (int i=1; i<=10; ++i)
    threads.emplace_back(increase_global,1000);

  cout << "increase counter (foo) with 10 threads using reference...\n";
  atomic<int> foo(0);
  for (int i=1; i<=10; ++i)
    threads.emplace_back(increase_reference,ref(foo),1000);

  cout << "synchronizing all threads...\n";
  for (auto& th : threads) th.join();

  cout << "global_counter: " << global_counter << '\n';
  cout << "foo: " << foo << '\n';

  return 0;
}