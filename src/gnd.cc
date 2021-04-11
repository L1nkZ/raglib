// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include "raglib/gnd.h"

#include "kaitai/exceptions.h"

namespace raglib {

gnd_t::gnd_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gnd_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = this;
  m_texture_names = 0;
  m_tiles = 0;
  m_surfaces = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void gnd_t::_read() {
  m_magic = m__io->read_bytes(4);
  if (!(magic() == std::string("\x47\x52\x47\x4E", 4))) {
    throw kaitai::validation_not_equal_error<std::string>(
        std::string("\x47\x52\x47\x4E", 4), magic(), _io(),
        std::string("/seq/0"));
  }
  m_version = m__io->read_u2be();
  m_width = m__io->read_u4le();
  {
    uint32_t _ = width();
    if (!(_ <= 512)) {
      throw kaitai::validation_expr_error<uint32_t>(width(), _io(),
                                                    std::string("/seq/2"));
    }
  }
  m_height = m__io->read_u4le();
  {
    uint32_t _ = height();
    if (!(_ <= 512)) {
      throw kaitai::validation_expr_error<uint32_t>(height(), _io(),
                                                    std::string("/seq/3"));
    }
  }
  m_zoom = m__io->read_f4le();
  m_texture_count = m__io->read_u4le();
  {
    uint32_t _ = texture_count();
    if (!(_ <= 1024)) {
      throw kaitai::validation_expr_error<uint32_t>(texture_count(), _io(),
                                                    std::string("/seq/5"));
    }
  }
  m_texture_name_size = m__io->read_u4le();
  {
    uint32_t _ = texture_name_size();
    if (!(_ <= 1024)) {
      throw kaitai::validation_expr_error<uint32_t>(texture_name_size(), _io(),
                                                    std::string("/seq/6"));
    }
  }
  int l_texture_names = texture_count();
  m_texture_names = new std::vector<std::string>();
  m_texture_names->reserve(l_texture_names);
  for (int i = 0; i < l_texture_names; i++) {
    m_texture_names->push_back(m__io->read_bytes(texture_name_size()));
  }
  m_lightmap_cell_count = m__io->read_u4le();
  {
    uint32_t _ = lightmap_cell_count();
    if (!(_ <= 262144)) {
      throw kaitai::validation_expr_error<uint32_t>(
          lightmap_cell_count(), _io(), std::string("/seq/8"));
    }
  }
  m_lightmap_grid_size_x = m__io->read_u4le();
  {
    uint32_t _ = lightmap_grid_size_x();
    if (!(_ <= 8)) {
      throw kaitai::validation_expr_error<uint32_t>(
          lightmap_grid_size_x(), _io(), std::string("/seq/9"));
    }
  }
  m_lightmap_grid_size_y = m__io->read_u4le();
  {
    uint32_t _ = lightmap_grid_size_y();
    if (!(_ <= 8)) {
      throw kaitai::validation_expr_error<uint32_t>(
          lightmap_grid_size_y(), _io(), std::string("/seq/10"));
    }
  }
  m_lightmap_cell_size = m__io->read_u4le();
  {
    uint32_t _ = lightmap_cell_size();
    if (!(_ <= 8)) {
      throw kaitai::validation_expr_error<uint32_t>(lightmap_cell_size(), _io(),
                                                    std::string("/seq/11"));
    }
  }
  m_lightmap_data = m__io->read_bytes(
      ((((4 * lightmap_cell_count()) * lightmap_grid_size_x()) *
        lightmap_grid_size_y()) *
       lightmap_cell_size()));
  m_tile_count = m__io->read_u4le();
  {
    uint32_t _ = tile_count();
    if (!(_ <= 262144)) {
      throw kaitai::validation_expr_error<uint32_t>(tile_count(), _io(),
                                                    std::string("/seq/13"));
    }
  }
  int l_tiles = tile_count();
  m_tiles = new std::vector<tile_t*>();
  m_tiles->reserve(l_tiles);
  for (int i = 0; i < l_tiles; i++) {
    m_tiles->push_back(new tile_t(m__io, this, m__root));
  }
  int l_surfaces = (width() * height());
  m_surfaces = new std::vector<surface_t*>();
  m_surfaces->reserve(l_surfaces);
  for (int i = 0; i < l_surfaces; i++) {
    m_surfaces->push_back(new surface_t(m__io, this, m__root));
  }
}

gnd_t::~gnd_t() { _clean_up(); }

void gnd_t::_clean_up() {
  if (m_texture_names) {
    delete m_texture_names;
    m_texture_names = 0;
  }
  if (m_tiles) {
    for (std::vector<tile_t*>::iterator it = m_tiles->begin();
         it != m_tiles->end(); ++it) {
      delete *it;
    }
    delete m_tiles;
    m_tiles = 0;
  }
  if (m_surfaces) {
    for (std::vector<surface_t*>::iterator it = m_surfaces->begin();
         it != m_surfaces->end(); ++it) {
      delete *it;
    }
    delete m_surfaces;
    m_surfaces = 0;
  }
}

gnd_t::tile_t::tile_t(kaitai::kstream* p__io, gnd_t* p__parent, gnd_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_u = 0;
  m_v = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void gnd_t::tile_t::_read() {
  int l_u = 4;
  m_u = new std::vector<float>();
  m_u->reserve(l_u);
  for (int i = 0; i < l_u; i++) {
    m_u->push_back(m__io->read_f4le());
  }
  int l_v = 4;
  m_v = new std::vector<float>();
  m_v->reserve(l_v);
  for (int i = 0; i < l_v; i++) {
    m_v->push_back(m__io->read_f4le());
  }
  m_texture_id = m__io->read_u2le();
  m_light = m__io->read_u2le();
  m_color = m__io->read_bytes(4);
}

gnd_t::tile_t::~tile_t() { _clean_up(); }

void gnd_t::tile_t::_clean_up() {
  if (m_u) {
    delete m_u;
    m_u = 0;
  }
  if (m_v) {
    delete m_v;
    m_v = 0;
  }
}

gnd_t::surface_t::surface_t(kaitai::kstream* p__io, gnd_t* p__parent,
                            gnd_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_height = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void gnd_t::surface_t::_read() {
  int l_height = 4;
  m_height = new std::vector<float>();
  m_height->reserve(l_height);
  for (int i = 0; i < l_height; i++) {
    m_height->push_back(m__io->read_f4le());
  }
  m_tile_up = m__io->read_s4le();
  m_tile_front = m__io->read_s4le();
  m_tile_right = m__io->read_s4le();
}

gnd_t::surface_t::~surface_t() { _clean_up(); }

void gnd_t::surface_t::_clean_up() {
  if (m_height) {
    delete m_height;
    m_height = 0;
  }
}

}  // namespace raglib
