// vector:
// https://cplusplus.com/reference/vector/vector/

// TODO: remaining functions: iterators, emplace, emplace_back etc.

#include <iostream>
#include <vector>

using namespace std;

void printMetadataAndContent(const vector<int> &vec, const string &vec_name) {
  cout << "Capacity of " << vec_name << ": " << vec.capacity()
       << ", size: " << vec.size() << ", max size: " << vec.max_size() << "\n";

  // a way to check for empty vector. Another way is vec.size() == 0
  if (vec.empty()) {
    cout << vec_name << " is empty\n";
    return;
  }

  // front() returns ref to first element and back() returns ref to the last
  // element
  cout << "First element: " << vec.front() << ", last element: " << vec.back()
       << "\n";
  cout << "Content of " << vec_name << ":\n";
  /*for (const auto &n : vec) {
    cout << n << " ";
  }
  cout << "\n";*/

  // another way to print content of vector
  for (int i = 0; i < vec.size(); ++i) {
    // accessing each element of the vector using operator[]
    // cout << vec[i] << " ";

    // accessing each element using .at()
    cout << vec.at(i) << " ";

    // Note: The only diff b/w operator[] and .at():
    // .at(i) throws the exceptions (that aborts the execution)
    // std::out_of_range if i >= vec.size(). operator[i] does not throws any
    // exception. Infact, it is undefined behavior to access element at index >=
    // size(). Thus, elements at index >= size() should be accessed using
    // operator[].
  }
  cout << endl;
}

void assigningVectors(vector<int> &source) {
  // copy assignment
  vector<int> dest = source;
  cout << "Source after copy assignment:\n";
  for (const auto &n : source) {
    cout << n << " ";
  }
  cout << "\n";

  cout << "Dest after copy assignment:\n";
  for (const auto &n : dest) {
    cout << n << " ";
  }
  cout << "\n";

  vector<int> moved_dest = std::move(source);
  if (!source.empty()) {
    // this will never be printed because source is empty after move assignment
    cout << "Source after move assignment:\n";
    for (const auto &n : source) {
      cout << n << " ";
    }
    cout << "\n";
  }
  cout << "Moved dest after move assignment:\n";
  for (const auto &n : moved_dest) {
    cout << n << " ";
  }
  cout << "\n";

  vector<int> initializer_vec = {1, 3, 5, 7, 9, 11};
  cout << "Vec assigned using initializer list:\n";
  for (const auto &n : initializer_vec) {
    cout << n << " ";
  }
  cout << "\n";
}

void addToVector(vector<int> &vec) {
  // on reserving the capacity, the capacity becomes fixed
  vec.reserve(5);
  // capacity doubles everytime more space is neede if we don't reserve initially
  cout << "Capacity: " << vec.capacity() << ", size: " << vec.size() << "\n";
  for (auto &n : {2, 4, 6, 8, 10, 11}) {
    vec.push_back(n);
    cout << "Capacity: " << vec.capacity() << ", size: " << vec.size() << "\n";
  }

  // removing last element
  vec.pop_back();
}

int main() {
  // no elements in first vector, initial capacity 0, intial size 0
  vector<int> first;
  // 5 elements in second vector, all 0s (or the zero value of the element
  // type), initial capacity 5, initial size 5
  vector<int> second(5);
  // 10 elements in third vector, all 1s, initial capacity 10, initial size 10
  vector<int> third(10, 1);
  // fourth vector is initialized using initializer_list
  vector<int> fourth({1, 2, 3, 4, 5, 6});

  printMetadataAndContent(first, "first");
  printMetadataAndContent(second, "second");
  printMetadataAndContent(third, "third");
  printMetadataAndContent(fourth, "fourth");

  // fifth vector is contructed via range based constructor using fourth vector
  vector<int> fifth(fourth.begin(), fourth.end());
  printMetadataAndContent(fifth, "fifth");

  assigningVectors(fifth);
  if (fifth.empty()) {
    cout << "\nfifth vec is empty now\n";
  }

  // remove all elements from the fourth vector making its size() == 0, but
  // capacity does not necessarily change.
  fourth.clear();
  printMetadataAndContent(fourth, "fourth");

  cout << "\nUpdating first vector\n";
  addToVector(first);
  cout << "\nPrinting first after update:\n";
  printMetadataAndContent(first, "first");

  first.resize(8);
  // earlier size was 5, new size: 8, newly added three elements will be all 0s.
  cout << "\nPrinting first after resize to 8:\n";
  printMetadataAndContent(first, "first");

  first.resize(12, 1);
  // earlier size was 8, new size: 12, newly added three elements will be all 1s.
  // capacity also increased from 10 to 16.
  cout << "\nPrinting first after another resize to 12:\n";
  printMetadataAndContent(first, "first");

  first.resize(4);
  // elelments are deleted from vector if resized to less than current size
  cout << "\nPrinting first after another resize to 4:\n";
  printMetadataAndContent(first, "first");

  return 0;
}