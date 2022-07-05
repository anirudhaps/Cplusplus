#include <iostream>

using namespace std;

void stringCreation() {
  // important link to differentiate b/w copy construction vs using assignment
  // operator:
  // https://stackoverflow.com/questions/11706040/whats-the-difference-between-assignment-operator-and-copy-constructor

  // string creation using assignment operator: this invokes the copy
  // constructor. "zero_str" is a string literal which is value of type
  // const char* i.e. c-style string
  string zero = "zero_str";
  cout << "zero string: " << zero << "\n";

  string one; // empty string
  cout << "one string: " << one << "\n";

  // creation of string using copy constructor; two == "zero_str"
  string two(zero);
  cout << "two string: " << two << "\n";

  // c-style string
  const char *cstr = "third_str";
  // creation of string object using c-style string
  string three(cstr);
  cout << "three string: " << three << "\n";
  string four("fourth_str");
  cout << "four string: " << four << "\n";

  // take first 4 chars of the buffer pointed by cstr and create string object
  // out of it
  string five(cstr, 4);
  cout << "five string: " << five << "\n";

  // create a string object and fill it with 6 copies of 's'
  string six(6, 's');
  cout << "six string: " << six << "\n";
  string using_ascii(6, 42);
  cout << "string created using ascii value: " << using_ascii << "\n";

  // create a string object by picking 3 characters from zero string starting
  // from the index 4 of zero string. Thus, seven will be a substring of zero.
  // length of seven will be 3.
  string seven(zero, 4, 3);
  cout << "seven string: " << seven << "\n";

  // create a string using initializer list
  string eight({'a', 'n', 'i', 'r', 'u', 'd', 'h', 'a'});
  cout << "eight string: " << eight << "\n";
  cout << "Lenght of eight string: " << eight.length() << "\n";
  // length can also be calculated by .size() method.

  // create string using range constructor.
  // takes the first six characters of four string starting from the beginning
  string nine(four.begin(), four.begin() + 6);
  cout << "nine string: " << nine << "\n";

  // create string using move constructor, zero string will become empty after
  // this operation
  string ten(std::move(zero));
  cout << "ten string: " << ten << "\n";
  if (zero.empty()) {
    cout << "zero string is empty\n";
  }

  cout << "max size of the string that can be created: " << ten.max_size()
       << "\n";

  // In the following cases, overloaded = operator methods are invoked
  // (specified at: https://cplusplus.com/reference/string/string/operator=/)
  string eleven, twelve, thirteen, fourteen;
  // updating value of string using assignment operator: move assignment
  eleven = std::move(ten);
  cout << "eleven string: " << eleven << "\n";
  if (ten.empty()) {
    cout << "ten string is empty\n";
  }

  // updating value of string using assignment operator: copy assignment
  twelve = eleven;
  cout << "twelve string: " << twelve << "\n";

  // updating value of string using assignment operator: single char assignment
  thirteen = 't';
  cout << "thirteen string: " << thirteen << "\n";

  // updating value of string using assignment operator: c-style string
  // assignment
  fourteen = "fourteen";
  cout << "fourteen string: " << fourteen << "\n";
}

void operations() {
  cout << "\n\n";
  string hello = "hello";
  cout << "hello string before: " << hello << "\n";
  hello.clear();
  if (hello.empty()) {
    cout << "hello string is empty\n";
  }

  // concatenation
  string host = "customer";
  string subdomain("support.microsoft");
  string fqdn;
  fqdn = host + '.' + subdomain + ".com";
  cout << "fqdn: " << fqdn << "\n";

  string scheme("https");
  // appending a c-style string literal
  scheme += "://";
  // appending string to another
  string url = scheme;
  url += fqdn;
  // appending single character to string
  url += '/';
  cout << "url: " << url << "\n";
  string old_url("http://hello.com/path/a.txt");
  // appending a substring of another string
  // path/ is appended. Note: 5 is length, 17 is starting pos in old_url
  url.append(old_url, 17, 5);
  cout << "updated url: " << url << "\n";
  // appending 5 times 'x'
  url.append(5, 'x');
  cout << "1-further updated url: " << url << "\n";
  // append a single char using push_back()
  url.push_back('/');
  cout << "2-further updated url: " << url << "\n";

  // insert at pos (see more overloaded methods of insert() online)
  url.insert(44, "sub-");
  cout << "3-further updated url: " << url << "\n";

  // replace part of the string starting from pos 48, replace 5 chars by string
  // "path". (see more overloaded methods of replace() online)
  url.replace(48, 5, "path");
  cout << "4-further updated url: " << url << "\n";

  // erase last character
  url.pop_back();
  cout << "5-further updated url: " << url << "\n";

  // erase a substring of the string; 39- starting pos, 5-len of substr or num
  // of chars to be erased.
  url.erase(39, 5);
  cout << "6-further updated url: " << url << "\n";

  cout << "first char of url: " << url.front()
       << ", last char of url: " << url.back() << "\n";

  // updating front and last chars of a string
  string zone = "zone";
  cout << "\nBefore: " << zone << "\n";
  // front() and back() return direct reference to the first and last characters
  // of a string respectively.
  zone.front() = 'd';
  zone.back() = 't';
  cout << "After: " << zone << "\n";
  // accessing/assigning a char in a string
  zone[3] = 'e';
  zone.at(0) = 'g';
  // difference b/w operator[] and .at(): .at() checks and throws out_of_range
  // exception if we try to access a char at pos >= string's length, while
  // operator[] doesn't throw an exception but accessing or assigning to pos >
  // str.length() using operator[] results in undefined behavior.
  cout << "Later: " << zone << "\n";
  // printing char by char
  for (int i = 0; i < zone.length(); ++i) {
    cout << zone[i] << " ";
  }
  cout << "\n";
}

void moreOperations() {
  string source = "customer.support.microsoft.com";
  // finding a string in another string
  auto pos = source.find("support");
  if (pos != string::npos) {
    cout << "pos where support is: " << pos << "\n";
    // taking substr starting from pos+8 and spanning till the end of the string
    auto domain = source.substr(pos + 8);
    // taking substr starting from position 0 and of len 9
    auto immediate_dns = domain.substr(0, 9);
    cout << "domain for support dns: " << domain
         << ", immediate dns server name: " << immediate_dns << "\n";
  }

  // trying to find a single char
  pos = source.find('k');
  if (pos == string::npos) {
    cout << "k not found in " << source << "\n";
  }

  // find "microsoft" from the end of the string source
  pos = source.rfind("microsoft");
  if (pos != string::npos) {
    cout << "microsoft substring found at: " << pos << "\n";
  }

  string dns = "dns.support.microsoft.com";
  auto relation = dns.compare(source);
  if (relation == 0) {
    cout << "dns and customer sites have same url\n";
  } else if (relation < 0) {
    cout << "dns site url is lesser\n";
  } else {
    // relation > 0
    cout << "dns site url is larger\n";
  }
}

int main() {
  stringCreation();
  operations();
  moreOperations();
  return 0;
}