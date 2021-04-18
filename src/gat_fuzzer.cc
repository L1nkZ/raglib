#include <raglib/gat.h>

#include <cstddef>
#include <cstdint>
#include <sstream>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *p_data, size_t size) {
  std::istringstream is(
      std::string(reinterpret_cast<const char *>(p_data), size));
  kaitai::kstream ks(&is);
  try {
    const raglib::gat_t gat(&ks);
  } catch (std::exception &) {
  }
  return 0;
}
