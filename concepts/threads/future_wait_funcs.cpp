#include <future>
#include <iostream>

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
  return sum;
}

int main() {
  std::future<int> result = std::async(std::launch::async, operation, 10);
  std::cout << "Main thread continues...\n";

  if (result.valid()) {
    // result.wait();
    // This wait call will wait until the shared state becomes available in the
    // future object. But it won't return the shared state. To access the shared
    // state, we still have to call the .get() on future. This will block the
    // main thread until the shared state is available.

    // This call will wait for 4s for shared state to become available in the
    // future.
    auto status = result.wait_for(4s);
    switch (status) {
    case std::future_status::deferred:
      std::cout << "The task is synchronous\n";
      // This state is returned when the launch policy is of type
      // std::launch::deferred. In this case, the wait_for() here won't wait for
      // 4s, it will immediately return with this status. This means the task
      // will be synchronously running and there is no point in waiting as the
      // task will actually run when .get() is called on the future.
      break;
    case std::future_status::ready:
      std::cout << "The task is ready - feel free to invoke .get() on future "
                   "to get the shared state\n";
      // This status is retuned when the task is completed and the shared state
      // is available in the future. This indicates that now we can invoke
      // .get() on the future to get the shared state.
      break;
    case std::future_status::timeout:
      std::cout << "The task is still running\n";
      // If we wait for lesser amount of time (eg. task takes 3s to complete and
      // we wait for only 1s), timeout status will be returned. This indicates
      // that the task is still running and wait_for call returned early. We
      // didn't wait long enough.
      break;
    }
    // wait_for() is generally invoked in a loop where it waits for the shared
    // state to become ready in the future object. And then we can break the
    // loop and access the shared state via .get() call on future object.

    // The only difference b/w wait_for and wait_until is that wait_until()
    // takes a time point in future time whereas wait_for() takes duration.
    // auto timepoint = std::chrono::system_clock::now() + 2s;
    // auto status = result.wait_until(timepoint);

    auto sum = result.get();
    std::cout << "Sum from future: " << sum << "\n";
  }
  return 0;
}