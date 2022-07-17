#include <future>
#include <iostream>

// needed for using 300ms as arg in sleep_for
using namespace std::chrono_literals;

// This is the task/callable that will be executed in a separate thread
int operation(int count) {
  int sum{};
  for (int i = 0; i < count; ++i) {
    sum += i;
    std::cout << '.';
    std::this_thread::sleep_for(300ms);
  }
  std::cout << "\n";
  // This sum is the shared state between this thread and main thread and this
  // will be available in the std::future as result when this task returns.
  return sum;
}

int main() {
  // Because the callable operation returns an int, the template type arg in the
  // std::future<> should be int. Here, 10 will be the argument passed to
  // operation().
  // It seems the std::async is by default using std::launch::async as lanch
  // policy. We can explicitly mention it as shown below:
  // std::future<int> result = std::async(std::launch::async, operation, 10);

  // To run operation() synchronously, use deferred launch policy. In this case,
  // operation() task will be executed when main thread tries to get the shared
  // state. i.e. when result.get() is invoked. This is as good as calling
  // operation() directly in place of result.get().
  std::future<int> result = std::async(std::launch::deferred, operation, 10);

  // std::future<int> result = std::async(operation, 10);
  std::this_thread::sleep_for(1s);
  std::cout << "Main thread continues...\n";

  if (result.valid()) {
    // The shared state will become available via this get() call and until this
    // become available, this get() call will block the main thread.
    // Important note: once you call get() on the future, the shared state is
    // destroyed and you cannot get it again. Also, the future (result here)
    // becomes invalid. The .valid() call is used to check if a future is valid
    // or not. If it is valid, then only we ar calling the get() it to get the
    // shared state.
    auto sum = result.get();
    std::cout << "Sum from future: " << sum << "\n";
  }
  return 0;
}