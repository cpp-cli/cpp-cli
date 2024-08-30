#include <cpp_cli/cpp_cli.h>

namespace cli {
void Command::callback(Command::callback_t callback) noexcept {
  callback_ = std::move(callback);
}
}  // namespace cli