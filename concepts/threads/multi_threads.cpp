#include <iostream>
#include <list>
#include <mutex>
#include <thread>


std::list<int> g_data;
constexpr int SIZE = 10000;
std::mutex g_mutex;

void download1() {
  for (int i = 0; i < SIZE; ++i) {
    g_mutex.lock();
    g_data.push_back(i);
    // at this point, if some exception is thrown or function is returned, this
    // mutex will never be unlocked and deadlock will happen. To avoid this, use
    // std::lock_guard.
    g_mutex.unlock();
  }
}

void download2() {
  for (int i = 0; i < SIZE; ++i) {
    g_mutex.lock();
    g_data.push_back(i);
    g_mutex.unlock();
  }
}

int main() {
  std::cout << "[Main] Started an operation\n";

  std::thread th_downloader1(download1);
  std::thread th_downloader2(download2);

  th_downloader1.join();
  th_downloader2.join();

  // Due to race condition between the threads, different runs will give
  // different list sizes. To avoid, use mutex for syncronization.
  std::cout << "list size: " << g_data.size() << "\n";
  std::cout << "[Main] User started another operation\n";
  return 0;
}