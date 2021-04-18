// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include "raglib/gat.h"

#include "kaitai/exceptions.h"

namespace raglib {

gat_t::gat_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, gat_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = this;
  m_cells = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void gat_t::_read() {
  m_magic = m__io->read_bytes(4);
  if (!(magic() == std::string("\x47\x52\x41\x54", 4))) {
    throw kaitai::validation_not_equal_error<std::string>(
        std::string("\x47\x52\x41\x54", 4), magic(), _io(),
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
  int l_cells = (width() * height());
  m_cells = new std::vector<cell_t*>();
  m_cells->reserve(l_cells);
  for (int i = 0; i < l_cells; i++) {
    m_cells->push_back(new cell_t(m__io, this, m__root));
  }
}

gat_t::~gat_t() { _clean_up(); }

void gat_t::_clean_up() {
  if (m_cells) {
    for (std::vector<cell_t*>::iterator it = m_cells->begin();
         it != m_cells->end(); ++it) {
      delete *it;
    }
    delete m_cells;
    m_cells = 0;
  }
}

gat_t::cell_t::cell_t(kaitai::kstream* p__io, gat_t* p__parent, gat_t* p__root)
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

void gat_t::cell_t::_read() {
  int l_height = 4;
  m_height = new std::vector<float>();
  m_height->reserve(l_height);
  for (int i = 0; i < l_height; i++) {
    m_height->push_back(m__io->read_f4le());
  }
  m_type = m__io->read_u4le();
}

gat_t::cell_t::~cell_t() { _clean_up(); }

void gat_t::cell_t::_clean_up() {
  if (m_height) {
    delete m_height;
    m_height = 0;
  }
}

}  // namespace raglib
