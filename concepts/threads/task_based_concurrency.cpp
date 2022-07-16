// Include <future> to use std::async
#include <future>
#include <iostream>

// In task based concurrency, this is a task that runs in a separate thread
void downloader() {
  using namespace std::chrono_literals;
  for (int i = 0; i < 10; ++i) {
    std::cout << '.' << std::endl;
    // using chrono_literals allows using 300ms, 3s etc. literals
    std::this_thread::sleep_for(300ms);
  }
}

int main() {
  // This is high-level or task based concurrency constructs because here we are
  // not directly using the thread class, mutexes, lock guard etc.
  // The type param in future is void because the downloader() returns a void.

  // std::async executes a callable in a separate thread
  std::future<void> result = std::async(downloader);

  // std::aync returns a future type object which provides access to the result
  // of the callable.

  // If we don't assign the returned future type object to some
  // variable, the std::async call will block the main thread. That is, the
  // following will block the main thread until the child thread returns.
  // std::async(downloader);

  // std::async has two overloads:
  // - std::future<return_type> std::async(Callable, args);
  // - std::future<return_type> std::async(Launcy_policy, Callable, args);

  // Launch policies:
  // - std::launch::deferred - the task is executed synchronously
  // - std::launch::async - the task is executed asynchronously

  // If no launch policy is specified in async call, it depends on the compiler
  // whether or not it will create a new thread or not. To force the async to
  // execute task asyncronously (in a separate thread), then use async launch
  // policy explicitly. In case we specify async launch policy and thread can't
  // be created with it, std::system_error exception is thrown.

  // The task arguments can be specified in std::async for the task.
  // By default, the args are passed by value.
  // To pass by reference, use reference wrappers: std::ref or std::cref.
  // To get the value from a task, simply return it from the task/function.
  // The returned value is available through the std::future object.

  // std::future is used for communication b/w the threads.
  // Has a shared state that can be accessed in a different thread.
  // Created through a std::promise object.
  //   - created by std::async that directly returns a future object
  //   - std::promise is an input channel
  //   - std::future is an output channel
  // The thread that reads the shared state will wait until the future is ready
  // with the shared state.
  // promise/future allow safe data sharing between threads.

  std::cout << "main thread continues..\n";
  result.get();
  return 0;
}