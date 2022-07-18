#include <future>
#include <iostream>

/**
 * Promise:
 * - provides a way to store a value or an exception.
 * - This is called the shared state of the promise.
 * - This state can be accessed later from another thread through a future
 *   object.
 * - promise/future are two endpoints of a communication channel.
 * - One operation stores a value in a promise and the other operation will
 *   retrieve it through a future asynchronously.
 * - These operations are synchronized, therefore, thread-safe.
 * - promise object can be used only once. i.e. you can set the value in it only
 *   once.
 * - Thus, promise and future objects are used to share data b/w different
 *   threads in thread-safe manner without having to use synchronization.
 * - One thread might have a promise object on which that thread will set the
 *   shared state and another thread might have a future object that is waiting
 *   for that shared state.
 * - The shared state can be manually set on the promise or the shared state
 *   could be return value from a task (i.e. if returned from a task, that value
 *   will automatically be set on a promise object).
 * - As soon as the shared state is set on the promise, it will be available via
 *   future in another thread. So if the other thread was waiting for shared
 *   state to become available, the wait will be over.
 * - Once the receiving thread acquires the shared state from future object, the
 *   shared state is destroyed and the future becomes invalid. This means you
 *   can't call get again on the future.
 */

using namespace std::chrono_literals;

int getSum(std::promise<int> &data) {
  // Get the future object from the promise object
  auto future_ = data.get_future();
  // Get the value set on the promise via future object.
  // Until the main thread sets data on the promise, this get() call will block
  // this thread.
  std::cout << "[Task] waiting for the count..\n";
  auto count = future_.get();
  std::cout << "[Task] count acquired..\n";
  int sum{};
  for (int i = 0; i < count; ++i) {
    sum += i;
    std::cout << '.';
    std::this_thread::sleep_for(300ms);
  }
  // returning shared state that will be accessible via future object of/in the
  // main thread.
  return sum;
}

int main() {
  std::promise<int> data;
  // passing promise object by reference to the callable getSum() which will run
  // in a separate thread.
  std::future<int> result =
      std::async(std::launch::async, getSum, std::ref(data));
  std::this_thread::sleep_for(2s);
  std::cout << "[Main] Setting the data in promise...\n";
  // this will unblock the other thread who is waiting for this value to be set.
  data.set_value(10);
  if (result.valid()) {
    auto sum = result.get();
    std::cout << sum << std::endl;
  }
  return 0;
}