#ifndef SPR_H_
#define SPR_H_

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

class spr_t : public kaitai::kstruct {
 public:
  class rgba_image_t;
  class rle_runs_t;
  class indexed_image_t;
  class indexed_rle_image_t;
  class rle_run_t;

  spr_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0,
        spr_t* p__root = 0);

 private:
  void _read();
  void _clean_up();

 public:
  ~spr_t();

  class rgba_image_t : public kaitai::kstruct {
   public:
    rgba_image_t(kaitai::kstream* p__io, spr_t* p__parent = 0,
                 spr_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~rgba_image_t();

   private:
    uint16_t m_width;
    uint16_t m_height;
    std::string m_data;
    spr_t* m__root;
    spr_t* m__parent;

   public:
    uint16_t width() const { return m_width; }
    uint16_t height() const { return m_height; }
    std::string data() const { return m_data; }
    spr_t* _root() const { return m__root; }
    spr_t* _parent() const { return m__parent; }
  };

  class rle_runs_t : public kaitai::kstruct {
   public:
    rle_runs_t(kaitai::kstream* p__io,
               spr_t::indexed_rle_image_t* p__parent = 0, spr_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~rle_runs_t();

   private:
    std::vector<rle_run_t*>* m_runs;
    spr_t* m__root;
    spr_t::indexed_rle_image_t* m__parent;

   public:
    std::vector<rle_run_t*>* runs() const { return m_runs; }
    spr_t* _root() const { return m__root; }
    spr_t::indexed_rle_image_t* _parent() const { return m__parent; }
  };

  class indexed_image_t : public kaitai::kstruct {
   public:
    indexed_image_t(kaitai::kstream* p__io, spr_t* p__parent = 0,
                    spr_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~indexed_image_t();

   private:
    uint16_t m_width;
    uint16_t m_height;
    std::string m_data;
    spr_t* m__root;
    spr_t* m__parent;

   public:
    uint16_t width() const { return m_width; }
    uint16_t height() const { return m_height; }
    std::string data() const { return m_data; }
    spr_t* _root() const { return m__root; }
    spr_t* _parent() const { return m__parent; }
  };

  class indexed_rle_image_t : public kaitai::kstruct {
   public:
    indexed_rle_image_t(kaitai::kstream* p__io, spr_t* p__parent = 0,
                        spr_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~indexed_rle_image_t();

   private:
    uint16_t m_width;
    uint16_t m_height;
    uint16_t m_data_size;
    rle_runs_t* m_rle_runs;
    spr_t* m__root;
    spr_t* m__parent;
    std::string m__raw_rle_runs;
    kaitai::kstream* m__io__raw_rle_runs;

   public:
    uint16_t width() const { return m_width; }
    uint16_t height() const { return m_height; }
    uint16_t data_size() const { return m_data_size; }
    rle_runs_t* rle_runs() const { return m_rle_runs; }
    spr_t* _root() const { return m__root; }
    spr_t* _parent() const { return m__parent; }
    std::string _raw_rle_runs() const { return m__raw_rle_runs; }
    kaitai::kstream* _io__raw_rle_runs() const { return m__io__raw_rle_runs; }
  };

  class rle_run_t : public kaitai::kstruct {
   public:
    rle_run_t(kaitai::kstream* p__io, spr_t::rle_runs_t* p__parent = 0,
              spr_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~rle_run_t();

   private:
    uint8_t m_value;
    uint8_t m_count;
    bool n_count;

   public:
    bool _is_null_count() {
      count();
      return n_count;
    };

   private:
    spr_t* m__root;
    spr_t::rle_runs_t* m__parent;

   public:
    uint8_t value() const { return m_value; }
    uint8_t count() const { return m_count; }
    spr_t* _root() const { return m__root; }
    spr_t::rle_runs_t* _parent() const { return m__parent; }
  };

 private:
  std::string m_magic;
  uint16_t m_version;
  uint16_t m_indexed_image_count;
  uint16_t m_rgba_image_count;
  bool n_rgba_image_count;

 public:
  bool _is_null_rgba_image_count() {
    rgba_image_count();
    return n_rgba_image_count;
  };

 private:
  std::vector<indexed_image_t*>* m_indexed_images;
  bool n_indexed_images;

 public:
  bool _is_null_indexed_images() {
    indexed_images();
    return n_indexed_images;
  };

 private:
  std::vector<indexed_rle_image_t*>* m_indexed_rle_images;
  bool n_indexed_rle_images;

 public:
  bool _is_null_indexed_rle_images() {
    indexed_rle_images();
    return n_indexed_rle_images;
  };

 private:
  std::vector<rgba_image_t*>* m_rgba_images;
  std::string m_palette;
  bool n_palette;

 public:
  bool _is_null_palette() {
    palette();
    return n_palette;
  };

 private:
  spr_t* m__root;
  kaitai::kstruct* m__parent;

 public:
  /**
   * File identification, must be "SP"
   */
  std::string magic() const { return m_magic; }
  uint16_t version() const { return m_version; }
  uint16_t indexed_image_count() const { return m_indexed_image_count; }
  uint16_t rgba_image_count() const { return m_rgba_image_count; }
  std::vector<indexed_image_t*>* indexed_images() const {
    return m_indexed_images;
  }
  std::vector<indexed_rle_image_t*>* indexed_rle_images() const {
    return m_indexed_rle_images;
  }
  std::vector<rgba_image_t*>* rgba_images() const { return m_rgba_images; }
  std::string palette() const { return m_palette; }
  spr_t* _root() const { return m__root; }
  kaitai::kstruct* _parent() const { return m__parent; }
};

}  // namespace raglib

#endif  // SPR_H_
