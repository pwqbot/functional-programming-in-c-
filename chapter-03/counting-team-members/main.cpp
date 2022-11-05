#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "../../common/person.h"

// See section 3.2.2
using std::count_if;

class company_t {
  public:
    [[nodiscard]] static auto team_name_for(const person_t & /*person*/)
        -> std::string;

    [[nodiscard]] auto count_team_members(const std::string &team_name) const
        -> int64_t;

  private:
    std::vector<person_t> m_employees;
};

auto company_t::team_name_for(const person_t &person) -> std::string {
    // Just for testing, you can implement this
    // properly for exercise
    return "Team1";
}

auto company_t::count_team_members(const std::string &team_name) const -> int64_t {
    // Counting the number of members in the specified team
    // using a lambda.
    //
    // The lambda needs to capture `this` because it needs to access
    // the `m_employees` member variable, and it captures the
    // `team_name` to check whether an employee belongs to that team
    return count_if(m_employees.cbegin(), m_employees.cend(),
                    [this, &team_name](const person_t &employee) {
                        return team_name_for(employee) == team_name;
                    });
}

auto main(int argc, char *argv[]) -> int {
    // Also for exercise, create an instance of the company_t object,
    // and test the count_team_members member function
}
