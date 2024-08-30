#include <cstdlib>

#include <cpp_cli/cpp_cli.h>

#include <catch2/catch_test_macros.hpp>

namespace cli {
TEST_CASE("When no callback is provided, then EXIT_SUCCESS is returned.") {
  auto command = Command{};

  static constexpr auto args = std::array<std::string_view, 0>{{}};
  auto const return_value = command.parse(cbegin(args), cend(args));

  CHECK(return_value == EXIT_SUCCESS);
}

TEST_CASE(
    "The callback of a command gets called and its returned value returned "
    "when an empty list of arguments is parsed.") {
  auto command = Command{};

  auto number_of_calls = 0;
  auto const expected_return_value = 1;
  command.callback([&] {
    ++number_of_calls;
    return expected_return_value;
  });

  static constexpr auto args = std::array<std::string_view, 0>{{}};
  auto const return_value = command.parse(cbegin(args), cend(args));

  CHECK(number_of_calls == 1);
  CHECK(return_value == expected_return_value);
}
}  // namespace cli