#include <raglib/rsw.h>

#include <cstdint>
#include <string>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *p_data, size_t size) {
  std::string content(reinterpret_cast<const char *>(p_data), size);
  kaitai::kstream ks(content);
  try {
    const raglib::rsw_t rsw(&ks);
  } catch (std::exception &) {
  }
  return 0;
}
