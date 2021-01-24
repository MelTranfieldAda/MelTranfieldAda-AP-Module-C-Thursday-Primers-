#include <iostream>
#include <thread>

int sleepTime1 = 5;
int sleepTime2 = 10;

void sleepNow(int seconds = 10) {
  std::this_thread::sleep_for( std::chrono::milliseconds(seconds * 1000) ); 
}

void thread_function(int threadName, int duration) {
  std::cout << "Thread " << threadName << ": " << std::this_thread::get_id() << " started\n";
  
  sleepNow(duration);
  
  std::cout << "Thread " << threadName << ": " << std::this_thread::get_id() << " ended\n";
}

void thread_function1() {
  thread_function(1, sleepTime1);
}

void thread_function2() {
  thread_function(2, sleepTime2);
}

int main() {
std::cout << "Main Thread: " << std::this_thread::get_id() << " started\n";

std::thread t1(&thread_function1);
std::thread t2(&thread_function2);

t1.detach();
t2.detach();

// Since we are detaching t1 and t2 from main thread, main thread will successfully exit immediately 
std::cout << "Main Thread: " << std::this_thread::get_id() << " ended\n";
}