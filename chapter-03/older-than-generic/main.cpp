
#include <algorithm>
#include <iostream>
#include <vector>

#include "../../common/person.h"

// Implements a generic function object that compares an object's age
// against a predefined integer limit (section 3.1.4)
class older_than {
  public:
    explicit older_than(int limit) : m_limit(limit) {}

    // Defining a call operator as a template function,
    // we will create a generic function object
    // that deduces the type of its argument when invoked
    template <typename T>
    auto operator()(T &&object) const -> bool {
        return std::forward<T>(object).age() > m_limit;
    }

  private:
    int m_limit;
};

auto main(int argc, char *argv[]) -> int {
    std::vector<person_t> persons;

    older_than predicate(42);

    std::count_if(persons.cbegin(), persons.cend(), predicate);

    return 0;
}
