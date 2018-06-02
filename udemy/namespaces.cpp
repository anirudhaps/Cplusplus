#include <iostream>

/*
Namespaces:
===========
1. A namespace is a declarative region in C++ used for declaring C++ types.
These types can be class, structure, function, variable or even another
namespace. Thus, nesting of namespace is also possible.

2. Syntax:
namespace <name> {
    Definitions of
    (namespace, class, structure, function, variable, etc.)
}

3. The main benefit of a namespace is that it prevents name clashes.
Two programmers working on a same project might define functions having same
name / signature. This will lead to clash at compile-time. To avoid this, each
of those two same named functions can be defined inside their own namespaces (
or different namespaces) and thereafter, can be used with fully qualified names.

4. It also helps to modularize the code. 

5. The C++ standard library is in std namespace.

6. By creating a namespace, we create a scope. So, all the constructs (or C++ 
types) defined inside a namespace can be visible only inside that scope and 
cannot be accessed directly outside the namespace.

7. Namespace scoped types can be accessed outside the namespace by either
opening the namespace or by opening the specific type. Thus, there are three
ways to do so:
    o. Use a global using decarative and open the entire namespace:
    using namespace std;

    The drawback of this is that though you want to use only one type from that
    namespace but you have opened and made visible all the types from that
    namespace which might be problematic sometimes.
    o. Use the using declarative and open a specific type:
    using std::cout;

    This will make visible only cout object to our code, not other objects
    defined in std.
    o. Using the fully qualified name of the type from namespace:
    std::cout << "Hello" << std::endl;

    In this case, we don't have to use any using declarative.
*/

namespace basic {
    float calculate(float x, float y) {
        return x + y;
    }
}

namespace Avg {
    float calculate(float x, float y) {
        return (x + y) / 2;
    }
}

//nestead namespaces:
namespace sort {
    void quicksort() {

    }
    void mergesort() {

    }
    namespace comparison {
        void lessthan() {

        }
        void greaterthan() {

        }
    }
}

int main() {
    //float ret = Avg::calculate(2.3f, 4.5f);
    //float ret = basic::calculate(2.3f, 4.5f);
    using namespace basic;
    float ret = calculate(2.3f, 4.5f);
    //using namespace Avg;
    ret = Avg::calculate(2.3f, 4.5f);
    using namespace std;
    cout << "ret = " << ret << endl;
    //sort::comparison::lessthan();
    //sort::comparison::greaterthan();
    using namespace sort::comparison;
    lessthan();
    greaterthan(); 
    return 0;
}