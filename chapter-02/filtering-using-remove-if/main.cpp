#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../../common/person.h"

auto name(const person_t &person) -> std::string {
    return person.name();
}

auto is_female(const person_t &person) -> bool {
    return person.gender() == person_t::female;
}

auto is_not_female(const person_t &person) -> bool {
    return !is_female(person);
}

int main(int argc, char *argv[]) {
    std::vector<person_t> people{
        {"David", person_t::male},    {"Jane", person_t::female},
        {"Martha", person_t::female}, {"Peter", person_t::male},
        {"Rose", person_t::female},   {"Tom", person_t::male}};

    std::erase_if(people, is_not_female);

    for (const person_t &person : people) {
        std::cout << person.name() << '\n';
    }

    return 0;
}
