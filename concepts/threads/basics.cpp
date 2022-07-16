// Concurrency:
// - A property of an application where multiple components of an applications
//   can run simultaneously or concurrently.
// - Required by large applications
// - Allows efficient usage of the CPU
// - Achieved by creating multiple threads
// - C++11 added support for concurrency and has support for starting and
//   managing threads.

// Every application is given one thread to execute. This thread is called
// primary thread or main thread. This thread is responsible for performing all
// the operations in the application and is also responsible for taking the
// input. So, if this main thread is busy performing any operation than the
// application will not be able to take user input.
// Thus, it is prefered not to do any long running operation in the main thread
// and instead do it in a separate thread. Performing long running operation in
// the main thread can lead to bad user experience.

// std::thread class:
// - have to include <thread> header for using this class
// - accepts a callable (function pointer, function object, lambda function) as
//   constructor argument.
// - thread class executes the callable in a separate thread. (creates a new
//   thread for running the callable).
// - thread class creates a thread and returns immediately. It does not wait for
//   the thread to start.

#include <iostream>
#include <list>
#include <thread>

std::list<int> g_data;
constexpr int SIZE = 5000000;

void download(const std::string &filename) {
  std::cout << "[Downloader] Started download of file " << filename << "\n";
  for (int i = 0; i < SIZE; ++i) {
    g_data.push_back(i);
  }
  std::cout << "[Downloader] Finished download\n";
}

int main() {
  std::cout << "[Main] Started an operation\n";
  std::string filename{"hello.mp4"};
  // pass download() function as the first argument to the thread class
  // constructor. The following will not compile because the std::thread class'
  // constructor take second arg as r-value, and here I am trying to copy the
  // l-value to an r-value reference.
  // std::thread th_downloader(download, filename);

  std::thread th_downloader(download, std::ref(filename));
  // std::ref is used to create a reference like wrapper object that acts as a
  // reference using the original object. std::cref can be used create const
  // reference from another object.

  // At this point a new thread will be created and download()
  // function will execute in that thread. The main thread will continue its
  // execution and will not wait for the download to finish.

  // th_downloader.detach();

  // Now we have two threads: main thread and child thread.
  // But before child thread finishes, the main thread finishes, the thread
  // object is destroyed and the main() function returns and the exit process
  // function is called and the whole process is aborted.
  // In order to let the child thread complete before main thread finishes,
  // invoke join() on the child thread. This will cause the main thread to block
  // until the child thread finishes its execution.
  if (th_downloader.joinable()) {
    // joinable() returns true if the thread is joinable. A detached thread is
    // non-joinable.
    th_downloader.join();
  }
  // Note: call the join() on the child thread before the std::thread object is
  // destroyed.

  // If a child thread is executing a long running task and we don't want main
  // thread to wait for it, we can detach the child thread by calling detach()
  // on the child thread. Note: a detached thread is non-joinable, so we can't
  // call join() on a detached thread. Also, since no join is called on it, main
  // thread won't wait for the detached child thread to finish. A detached
  // thread will automatically release its resources when the std::thread object
  // is destroyed.
  std::cout << "[Main] User started another operation\n";
  return 0;
}
