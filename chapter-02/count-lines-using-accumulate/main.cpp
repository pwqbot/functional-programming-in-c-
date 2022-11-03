
#include <iostream>
#include <numeric>

// Implementing counting through folding.
// We have our previous count, and we are returning the new count
// after checking out the current character.
auto counter(int previous_count, char c) -> int {
    return (c != '\n') ? previous_count : previous_count + 1;
}

auto count_lines(const std::string &s) -> int {
    return std::accumulate(s.cbegin(), s.cend(), 0, counter);
}

auto main(int argc, char *argv[]) -> int {
    std::cout << count_lines("an ancient pond \n"
                             "a frog jumps in \n"
                             "the splash of water\n")
              << '\n';

    return 0;
}
