#include <iostream>

class Integer {
public:
  Integer() : number(0) { std::cout << "Integer()\n"; }
  Integer(int num) : number(num) { std::cout << "Integer(int)\n"; }
  Integer(const Integer &num) : number(num.number) {
    std::cout << "Integer(const Integer&)\n";
  }
  Integer(Integer &&num) : number(num.number) {
    std::cout << "Integer(Integer&&)\n";
    num.number = 0;
  }
  Integer &operator=(const Integer &num) {
    std::cout << "operator=(const Integer&)\n";
    number = num.number;
    return *this;
  }
  Integer &operator=(Integer &&num) {
    std::cout << "operator=(Integer&&)\n";
    number = num.number;
    num.number = 0;
    return *this;
  }

private:
  int number;
};

class Employee {
public:
  // To have all the combinations of l-value, r-value based construction of
  // object, we need the following four constructors:
  // Employee(const std::string &name, const Integer &id) : name_(name), id_(id)
  // {
  //   std::cout << "Employee(const std::string&, const Integer&)\n";
  // }

  // Employee(std::string &&name, Integer &&id)
  //     : name_(std::move(name)), id_(std::move(id)) {
  //   std::cout << "Employee(std::string&&, Integer&&)\n";
  // }

  // Employee(std::string &&name, const Integer &id)
  //     : name_(std::move(name)), id_(id) {
  //   std::cout << "Employee(std::string&&, const Integer&)\n";
  // }

  // Employee(const std::string &name, Integer &&id)
  //     : name_(name), id_(std::move(id)) {
  //   std::cout << "Employee(const std::string&, Integer&&)\n";
  // }

  // To avoid writing all these constructor, a constructor template can be
  // written. This template will be called a member template.
  // Here, if the constructor is invoked with l-values arguments, this template
  // will be instantiated with l-value parameters and  if the constructor is
  // invoked with r-values arguments, this template will be instantiated with
  // r-value parameters.
  template <typename T1, typename T2>
  Employee(T1 &&name, T2 &&id)
      : name_(std::forward<T1>(name)), id_(std::forward<T2>(id)) {
    // std::forward<T1> will cast name to an rvalue reference if and only if T1
    // is an rvalue reference type. Otherwise, it will remain an lvalue.
    std::cout << "Employee(T1 &&name, T2 &&id)\n";
  }

private:
  std::string name_;
  Integer id_;
};

int main() {
  // Employee emp("anirudha", 100);
  // Integer num(25);
  // std::string name{"anirudha"};
  // Employee emp2(name, num);
  Employee emp3("anirudha", Integer(25));
  // Employee emp4(name, 100);
  return 0;
}