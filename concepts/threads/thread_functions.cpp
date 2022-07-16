#include <iostream>
#include <thread>

void process() {
  // print the id of this thread, this will be same as the one printed in the
  // main.
  std::cout << "[Child Thread]: thread id: " << std::this_thread::get_id()
            << "\n";
  // Applying sleep/delay to the thread
  for (int i = 0; i < 10; ++i) {
    // put 1s sleep before printing each value
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Note: without std::endl, the buffer will not be flushed after every 1s.
    // Instead, the numbers are put in an output buffer at delay of 1s and
    // flushed when the buffer is full or the function returns.
    std::cout << i << std::endl;
  }
}

int main() {
  std::thread t1(process);
  auto id = t1.get_id(); // returns an instance of std::thread::id class
  std::cout << id << std::endl;

  // getting the number of cores in the CPU
  // This can be useful to know how many threads can be created in the
  // application to maximize the performance.
  int cores = std::thread::hardware_concurrency();
  std::cout << "Number of cores: " << cores << std::endl;

  t1.join();
  return 0;
}