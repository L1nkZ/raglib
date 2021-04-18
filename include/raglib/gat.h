#ifndef GAT_H_
#define GAT_H_

// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include <stdint.h>

#include <vector>

#include "kaitai/kaitaistruct.h"

namespace raglib {

#if KAITAI_STRUCT_VERSION < 9000L
#error \
    "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif

class gat_t : public kaitai::kstruct {
 public:
  class cell_t;

  gat_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0,
        gat_t* p__root = 0);

 private:
  void _read();
  void _clean_up();

 public:
  ~gat_t();

  class cell_t : public kaitai::kstruct {
   public:
    cell_t(kaitai::kstream* p__io, gat_t* p__parent = 0, gat_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~cell_t();

   private:
    std::vector<float>* m_height;
    uint32_t m_type;
    gat_t* m__root;
    gat_t* m__parent;

   public:
    std::vector<float>* height() const { return m_height; }
    uint32_t type() const { return m_type; }
    gat_t* _root() const { return m__root; }
    gat_t* _parent() const { return m__parent; }
  };

 private:
  std::string m_magic;
  uint16_t m_version;
  uint32_t m_width;
  uint32_t m_height;
  std::vector<cell_t*>* m_cells;
  gat_t* m__root;
  kaitai::kstruct* m__parent;

 public:
  /**
   * File identification, must be "GRAT"
   */
  std::string magic() const { return m_magic; }
  uint16_t version() const { return m_version; }
  uint32_t width() const { return m_width; }
  uint32_t height() const { return m_height; }
  std::vector<cell_t*>* cells() const { return m_cells; }
  gat_t* _root() const { return m__root; }
  kaitai::kstruct* _parent() const { return m__parent; }
};

}  // namespace raglib

#endif  // GAT_H_
