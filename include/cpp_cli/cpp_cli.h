#ifndef CPP_CLI_COMMAND_H
#define CPP_CLI_COMMAND_H

#include <functional>
#include <utility>

namespace cli {
class Command {
 public:
  using return_t = int;
  using callback_t = std::function<return_t()>;

  void callback(callback_t callback) noexcept;

  template<class InputIt>
  return_t parse(InputIt first, InputIt last) const {
    return callback_();
  }

 private:
  callback_t callback_;
};
};  // namespace cli

#endif