#include <iostream>
#include <list>
#include <mutex>
#include <thread>

std::list<int> g_data;
constexpr int SIZE = 10000;
std::mutex g_mutex;

void download1() {
  for (int i = 0; i < SIZE; ++i) {
    // lock guard is a solution that implements RAII. That is, it is a manager
    // object for the mutex similar to unique_ptr object which is a manager
    // object of a raw pointer.
    std::lock_guard<std::mutex> mtx(g_mutex);
    g_data.push_back(i);

    // at this point, the mtx local object will be destroyed as it will go out
    // of scope and its destructor will internally unlock the underlyting
    // g_mutex
  }
}

void download2() {
  for (int i = 0; i < SIZE; ++i) {
    std::lock_guard<std::mutex> mtx(g_mutex);
    g_data.push_back(i);
  }
}

int main() {
  std::cout << "[Main] Started an operation\n";

  std::thread th_downloader1(download1);
  std::thread th_downloader2(download2);

  th_downloader1.join();
  th_downloader2.join();

  std::cout << "list size: " << g_data.size() << "\n";
  std::cout << "[Main] User started another operation\n";
  return 0;
}