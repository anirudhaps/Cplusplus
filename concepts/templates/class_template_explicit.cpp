#include <iostream>
#include <vector>

// This template forms a blueprint for printer classes of various types
template <typename T> class PrettyPrinter {
public:
  PrettyPrinter(T *data) : m_data(data) {}

  void print() const { std::cout << "{" << *m_data << "}" << std::endl; }

  T *getData() const { return m_data; }

private:
  T *m_data;
};

// Explicit specialization of print() function of PrettyPrinter template for
// type std::vector<int>. Here, we have not specialized whole of the
// PrettyPrinter class for type std::vector<int> because only issue was with the
// print() function of original PrettyPrinter template which was unable to print
// vector correctly.
template <> void PrettyPrinter<std::vector<int>>::print() const {
  std::cout << "{ ";
  for (auto num : *m_data) {
    std::cout << num << " ";
  }
  std::cout << "}" << std::endl;
}

// Explicit specialization of the print() function for type
// std::vector<std::vector<int>>
template <> void PrettyPrinter<std::vector<std::vector<int>>>::print() const {
  std::cout << "{\n";
  for (auto vec : *m_data) {
    std::cout << "  { ";
    for (auto num : vec) {
      std::cout << num << " ";
    }
    std::cout << "}\n";
  }
  std::cout << "}" << std::endl;
}

// Explicit specialization of PrettyPrinter class template for data type: const
// char*
template <> class PrettyPrinter<const char *> {
public:
  PrettyPrinter(const char *data) : m_data(data) {}

  void print() const { std::cout << "{" << m_data << "}" << std::endl; }

  const char *getData() const { return m_data; }

private:
  const char *m_data;
};

int main() {
  int val = 5;
  PrettyPrinter<int> printer(&val);
  printer.print();
  std::string str{"hello"};
  PrettyPrinter<std::string> printer2(&str);
  printer2.print();

  // const char *name = "aps";
  // PrettyPrinter<const char *> printer3(&name);
  // printer3.print();
  // The below is returning const char** so can't assign it to a const char*
  // const char *p = printer3.getData();

  // Note: because of pointer type, (const char *), all the above this become a
  // little difficult and counter-intuitive. To solve this problem, we can
  // define an explicit specialization of the above class template.

  // After explicit specialization for type const char*, all becomes intuitive:
  const char *name = "aps";
  PrettyPrinter<const char *> printer3(name);
  printer3.print();
  const char *p = printer3.getData();
  std::cout << "get: " << p << std::endl;

  std::vector<int> arr{1, 2, 3, 4, 5};
  PrettyPrinter<std::vector<int>> vecPrinter(&arr);

  /*
    vecPrinter.print();
    The above print will give the following compile time error:
    class_template_explicit.cpp: In instantiation of 'void
    PrettyPrinter<T>::print() const [with T = std::vector<int>]':
    class_template_explicit.cpp:58:20:   required from here
    class_template_explicit.cpp:9:41: error: no match for 'operator<<' (operand
    types are 'std::basic_ostream<char>' and 'std::vector<int>')
    9 |   void print() const { std::cout << "{" << *m_data << "}" << std::endl;
    }

    This is because *m_data is the vector and that we are trying to print using
    cout by using << operator which is not overloaded for the vector. The issue
    here is only with PrettyPrinter::print() function, so we can just specialize
    print() function for vector<int>.
  */

  // After specializing print() for std::vector<int>:
  vecPrinter.print();

  std::vector<std::vector<int>> matrix{{1, 2, 3}, {4, 5, 6}};
  PrettyPrinter<std::vector<std::vector<int>>> matrixPrinter(&matrix);
  // need to specialize print() here for std::vector<std::vector<int>> type.
  // Thus, this will invoke specialized print().
  matrixPrinter.print();
  return 0;
}