#include <raglib/spr.h>

#include <cstddef>
#include <cstdint>
#include <sstream>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *p_data, size_t size) {
  std::istringstream is(
      std::string(reinterpret_cast<const char *>(p_data), size));
  kaitai::kstream ks(&is);
  try {
    const raglib::spr_t spr(&ks);
  } catch (std::exception &) {
  }
  return 0;
}
