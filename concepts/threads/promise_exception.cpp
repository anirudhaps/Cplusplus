#include <future>
#include <iostream>

using namespace std::chrono_literals;

int getSum(std::promise<int> &data) {
  auto future_ = data.get_future();
  int sum{};
  try {
    std::cout << "[Task] waiting for the count..\n";
    // the exception set in the promise object will be thrown by the below get()
    // call in this thread.
    auto count = future_.get();
    std::cout << "[Task] count acquired..\n";
    for (int i = 0; i < count; ++i) {
      sum += i;
      std::cout << '.';
      std::this_thread::sleep_for(300ms);
    }
  } catch (std::exception &ex) {
    std::cout << "[Task] Exception: " << ex.what() << std::endl;
  }
  return sum;

  // To propagate an exception from this thread to the main thread, just throw
  // an exception here (without catching it in this thread). It will
  // automatically be propagated to other (main) thread and in the main thread,
  // the same exception will be thrown by result.get() so don't forget to catch
  // it there.
}

int main() {
  std::promise<int> data;
  std::future<int> result =
      std::async(std::launch::async, getSum, std::ref(data));
  std::this_thread::sleep_for(2s);
  std::cout << "[Main] Setting the data in promise...\n";

  // throwing exception in the main thread and propagating it to the other
  // thread.
  try {
    // deliberately throwing an exception
    throw std::runtime_error{"Data not available"};
    data.set_value(10);
    if (result.valid()) {
      auto sum = result.get();
      std::cout << sum << std::endl;
    }
  } catch (std::exception &ex) {
    // propagating exception to the other thread by setting it on promise
    // object, this requires creation of an exception pointer by passing
    // exception object.
    data.set_exception(std::make_exception_ptr(ex));
  }
  return 0;
}