#ifndef GND_H_
#define GND_H_

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

class gnd_t : public kaitai::kstruct {
 public:
  class tile_t;
  class surface_t;

  gnd_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0,
        gnd_t* p__root = 0);

 private:
  void _read();
  void _clean_up();

 public:
  ~gnd_t();

  class tile_t : public kaitai::kstruct {
   public:
    tile_t(kaitai::kstream* p__io, gnd_t* p__parent = 0, gnd_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~tile_t();

   private:
    std::vector<float>* m_u;
    std::vector<float>* m_v;
    uint16_t m_texture_id;
    uint16_t m_light;
    std::string m_color;
    gnd_t* m__root;
    gnd_t* m__parent;

   public:
    std::vector<float>* u() const { return m_u; }
    std::vector<float>* v() const { return m_v; }
    uint16_t texture_id() const { return m_texture_id; }
    uint16_t light() const { return m_light; }
    std::string color() const { return m_color; }
    gnd_t* _root() const { return m__root; }
    gnd_t* _parent() const { return m__parent; }
  };

  class surface_t : public kaitai::kstruct {
   public:
    surface_t(kaitai::kstream* p__io, gnd_t* p__parent = 0, gnd_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~surface_t();

   private:
    std::vector<float>* m_height;
    int32_t m_tile_up;
    int32_t m_tile_front;
    int32_t m_tile_right;
    gnd_t* m__root;
    gnd_t* m__parent;

   public:
    std::vector<float>* height() const { return m_height; }
    int32_t tile_up() const { return m_tile_up; }
    int32_t tile_front() const { return m_tile_front; }
    int32_t tile_right() const { return m_tile_right; }
    gnd_t* _root() const { return m__root; }
    gnd_t* _parent() const { return m__parent; }
  };

 private:
  std::string m_magic;
  uint16_t m_version;
  uint32_t m_width;
  uint32_t m_height;
  float m_zoom;
  uint32_t m_texture_count;
  uint32_t m_texture_name_size;
  std::vector<std::string>* m_texture_names;
  uint32_t m_lightmap_cell_count;
  int32_t m_lightmap_grid_size_x;
  int32_t m_lightmap_grid_size_y;
  int32_t m_lightmap_cell_size;
  std::string m_lightmap_data;
  uint32_t m_tile_count;
  std::vector<tile_t*>* m_tiles;
  std::vector<surface_t*>* m_surfaces;
  gnd_t* m__root;
  kaitai::kstruct* m__parent;

 public:
  /**
   * File identification, must be "GRGN"
   */
  std::string magic() const { return m_magic; }
  uint16_t version() const { return m_version; }
  uint32_t width() const { return m_width; }
  uint32_t height() const { return m_height; }
  float zoom() const { return m_zoom; }
  uint32_t texture_count() const { return m_texture_count; }
  uint32_t texture_name_size() const { return m_texture_name_size; }
  std::vector<std::string>* texture_names() const { return m_texture_names; }
  uint32_t lightmap_cell_count() const { return m_lightmap_cell_count; }
  int32_t lightmap_grid_size_x() const { return m_lightmap_grid_size_x; }
  int32_t lightmap_grid_size_y() const { return m_lightmap_grid_size_y; }
  int32_t lightmap_cell_size() const { return m_lightmap_cell_size; }
  std::string lightmap_data() const { return m_lightmap_data; }
  uint32_t tile_count() const { return m_tile_count; }
  std::vector<tile_t*>* tiles() const { return m_tiles; }
  std::vector<surface_t*>* surfaces() const { return m_surfaces; }
  gnd_t* _root() const { return m__root; }
  kaitai::kstruct* _parent() const { return m__parent; }
};

}  // namespace raglib

#endif  // GND_H_
