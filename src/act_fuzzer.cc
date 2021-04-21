#include <raglib/act.h>

#include <cstddef>
#include <cstdint>
#include <sstream>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *p_data, size_t size) {
  auto content = std::string(reinterpret_cast<const char *>(p_data), size);
  kaitai::kstream ks(content);
  try {
    const raglib::act_t act(&ks);
  } catch (std::exception &) {
  }
  return 0;
}
