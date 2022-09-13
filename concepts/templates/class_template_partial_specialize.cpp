#include <iostream>

// class template with one non-type template param
template <typename T, int columns> class PrettyPrinter {
public:
  PrettyPrinter(T *data) : m_data(data) {}

  void print() const {
    std::cout << "Columns: " << columns << std::endl;
    std::cout << "{ " << *m_data << " }" << std::endl;
  }

  T *getData() const { return m_data; }

private:
  T *m_data;
};

// Partially specializing only one of the template parameter. i.e. column
template <typename T> class PrettyPrinter<T, 80> {
public:
  PrettyPrinter(T *data) : m_data(data) {}

  void print() const {
    std::cout << "With 80 columns:" << std::endl;
    std::cout << "{ " << *m_data << " }" << std::endl;
  }

  T *getData() const { return m_data; }

private:
  T *m_data;
};

int main() {
  int data = 10;
  PrettyPrinter<int, 100> printer(&data);
  printer.print();

  // Here, the compiler will choose the specialized template for columns = 80
  PrettyPrinter<int, 80> printer1(&data);
  printer1.print();
  return 0;
}