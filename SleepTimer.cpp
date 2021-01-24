#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <algorithm>

void sleepNow(int seconds = 10) {
  std::this_thread::sleep_for( std::chrono::milliseconds(seconds * 1000) ); 
}

int main() {
  sleepNow(1);
  sleepNow();
}