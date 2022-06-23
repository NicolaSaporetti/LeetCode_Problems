#include <iostream>
#include <thread>
#include "Singleton.cpp"
using namespace std;

void ThreadFoo(){
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    cout << singleton->get_value() <<endl;
}

void ThreadBar(){
    this_thread::sleep_for(chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    cout<< singleton->get_value() <<endl;
}

int main()
{
    cout <<"If you see the same value, then singleton was reused (yay!\n" <<
           "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
           "RESULT:\n";   
    thread t1(ThreadFoo);
    thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}