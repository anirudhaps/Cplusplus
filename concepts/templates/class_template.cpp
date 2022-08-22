#include <iostream>

// T and size are template parameters. size is non-type template parameter.
template <typename T, int size> class Stack {
public:
  Stack() = default;

  // Using shorthand notation for the Stack obj declaration for the object that
  // is passed to the copy constructor because the constructor is defined inside
  // the class template.
  /*Stack(const Stack &obj) : m_top(obj.m_top) {
    for (int i = 0; i <= m_top; ++i) {
      arr[i] = obj.arr[i];
    }
  }*/

  // defining copy constructor outside the class template
  Stack(const Stack &obj);

  void push(const T &value) { arr[++m_top] = value; }

  // defining the pop() method outside the class
  void pop();

  bool isEmpty() const { return m_top == -1; }

  const T &top() const { return arr[m_top]; }

  // a factory method for this class
  // Inside the class template, there is no need for specifying the full type
  // Stack<T, size>. Stack below is the shorthand type.
  // static Stack create() { return Stack(); }

  // Defining this factory method outside the class template
  static Stack create();

private:
  int m_top{-1};
  T arr[size];
};

// When a member function of a template class defined outside of the class, the
// definition is preceded by template type params. i.e.
// template <typename T, int size>.
// Also, the type for the method is not just Stack, it is Stack<t, size>. i.e.
// the type for the template class contains type params.
template <typename T, int size> void Stack<T, size>::pop() { --m_top; }

// When the factory method is defined outside the template class, full Stack
// type i.e. Stack<T, size> has to be specified.
template <typename T, int size> Stack<T, size> Stack<T, size>::create() {
  return Stack();
}

// When a copy costructor is defined outside the class template, we don't have
// to specify the full type in the Stack obj parameter. We can but we don't have
// to.
template <typename T, int size> Stack<T, size>::Stack(const Stack &obj) {
  m_top = obj.m_top;
  for (int i = 0; i <= m_top; ++i) {
    arr[i] = obj.arr[i];
  }
}

int main() {
  // This will make the compiler to instantiate the Stack for type int.
  // Only those member functions are instantiated that are invoked at least
  // once.
  Stack<int, 10> stk;
  stk.push(10);
  stk.push(20);
  stk.push(30);
  while (!stk.isEmpty()) {
    std::cout << stk.top() << " ";
    stk.pop();
  }
  std::cout << std::endl;

  auto s = Stack<float, 5>::create();
  s.push(2.1);
  s.push(3.2);
  // commenting this loop to keep all the elements pushed in the stack s and
  // this is being used as the arg to the copy constructor below.
  /*while (!s.isEmpty()) {
    std::cout << s.top() << " ";
    s.pop();
  }
  std::cout << std::endl;*/

  Stack<float, 5> s1(s);
  while (!s1.isEmpty()) {
    std::cout << s1.top() << " ";
    s1.pop();
  }
  std::cout << std::endl;
  return 0;
}