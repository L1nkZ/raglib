// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include "raglib/spr.h"

#include "kaitai/exceptions.h"

namespace raglib {

spr_t::spr_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, spr_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = this;
  m_indexed_images = 0;
  m_indexed_rle_images = 0;
  m_rgba_images = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void spr_t::_read() {
  m_magic = m__io->read_bytes(2);
  if (!(magic() == std::string("\x53\x50", 2))) {
    throw kaitai::validation_not_equal_error<std::string>(
        std::string("\x53\x50", 2), magic(), _io(), std::string("/seq/0"));
  }
  m_version = m__io->read_u2le();
  m_indexed_image_count = m__io->read_u2le();
  n_rgba_image_count = true;
  if (version() > 257) {
    n_rgba_image_count = false;
    m_rgba_image_count = m__io->read_u2le();
  }
  n_indexed_images = true;
  if (version() < 513) {
    n_indexed_images = false;
    int l_indexed_images = indexed_image_count();
    m_indexed_images = new std::vector<indexed_image_t*>();
    m_indexed_images->reserve(l_indexed_images);
    for (int i = 0; i < l_indexed_images; i++) {
      m_indexed_images->push_back(new indexed_image_t(m__io, this, m__root));
    }
  }
  n_indexed_rle_images = true;
  if (version() >= 513) {
    n_indexed_rle_images = false;
    int l_indexed_rle_images = indexed_image_count();
    m_indexed_rle_images = new std::vector<indexed_rle_image_t*>();
    m_indexed_rle_images->reserve(l_indexed_rle_images);
    for (int i = 0; i < l_indexed_rle_images; i++) {
      m_indexed_rle_images->push_back(
          new indexed_rle_image_t(m__io, this, m__root));
    }
  }
  int l_rgba_images = rgba_image_count();
  m_rgba_images = new std::vector<rgba_image_t*>();
  m_rgba_images->reserve(l_rgba_images);
  for (int i = 0; i < l_rgba_images; i++) {
    m_rgba_images->push_back(new rgba_image_t(m__io, this, m__root));
  }
  n_palette = true;
  if (((version() > 256) && (indexed_image_count() > 0))) {
    n_palette = false;
    m_palette = m__io->read_bytes(1024);
  }
}

spr_t::~spr_t() { _clean_up(); }

void spr_t::_clean_up() {
  if (!n_rgba_image_count) {
  }
  if (!n_indexed_images) {
    if (m_indexed_images) {
      for (std::vector<indexed_image_t*>::iterator it =
               m_indexed_images->begin();
           it != m_indexed_images->end(); ++it) {
        delete *it;
      }
      delete m_indexed_images;
      m_indexed_images = 0;
    }
  }
  if (!n_indexed_rle_images) {
    if (m_indexed_rle_images) {
      for (std::vector<indexed_rle_image_t*>::iterator it =
               m_indexed_rle_images->begin();
           it != m_indexed_rle_images->end(); ++it) {
        delete *it;
      }
      delete m_indexed_rle_images;
      m_indexed_rle_images = 0;
    }
  }
  if (m_rgba_images) {
    for (std::vector<rgba_image_t*>::iterator it = m_rgba_images->begin();
         it != m_rgba_images->end(); ++it) {
      delete *it;
    }
    delete m_rgba_images;
    m_rgba_images = 0;
  }
  if (!n_palette) {
  }
}

spr_t::rgba_image_t::rgba_image_t(kaitai::kstream* p__io, spr_t* p__parent,
                                  spr_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void spr_t::rgba_image_t::_read() {
  m_width = m__io->read_u2le();
  m_height = m__io->read_u2le();
  {
    uint16_t _ = height();
    if (!(((static_cast<std::streamsize>(width()) * height()) * 4) <=
          1073741824L)) {
      throw kaitai::validation_expr_error<uint16_t>(
          height(), _io(), std::string("/types/rgba_image/seq/1"));
    }
  }
  m_data = m__io->read_bytes(
      ((static_cast<std::streamsize>(width()) * height()) * 4));
}

spr_t::rgba_image_t::~rgba_image_t() { _clean_up(); }

void spr_t::rgba_image_t::_clean_up() {}

spr_t::rle_runs_t::rle_runs_t(kaitai::kstream* p__io,
                              spr_t::indexed_rle_image_t* p__parent,
                              spr_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_runs = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void spr_t::rle_runs_t::_read() {
  m_runs = new std::vector<rle_run_t*>();
  {
    int i = 0;
    while (!m__io->is_eof()) {
      m_runs->push_back(new rle_run_t(m__io, this, m__root));
      i++;
    }
  }
}

spr_t::rle_runs_t::~rle_runs_t() { _clean_up(); }

void spr_t::rle_runs_t::_clean_up() {
  if (m_runs) {
    for (std::vector<rle_run_t*>::iterator it = m_runs->begin();
         it != m_runs->end(); ++it) {
      delete *it;
    }
    delete m_runs;
    m_runs = 0;
  }
}

spr_t::indexed_image_t::indexed_image_t(kaitai::kstream* p__io,
                                        spr_t* p__parent, spr_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void spr_t::indexed_image_t::_read() {
  m_width = m__io->read_u2le();
  m_height = m__io->read_u2le();
  {
    uint16_t _ = height();
    if (!((static_cast<std::streamsize>(width()) * height()) <= 1073741824L)) {
      throw kaitai::validation_expr_error<uint16_t>(
          height(), _io(), std::string("/types/indexed_image/seq/1"));
    }
  }
  m_data =
      m__io->read_bytes((static_cast<std::streamsize>(width()) * height()));
}

spr_t::indexed_image_t::~indexed_image_t() { _clean_up(); }

void spr_t::indexed_image_t::_clean_up() {}

spr_t::indexed_rle_image_t::indexed_rle_image_t(kaitai::kstream* p__io,
                                                spr_t* p__parent,
                                                spr_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_rle_runs = 0;
  m__io__raw_rle_runs = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void spr_t::indexed_rle_image_t::_read() {
  m_width = m__io->read_u2le();
  m_height = m__io->read_u2le();
  m_data_size = m__io->read_u2le();
  m__raw_rle_runs = m__io->read_bytes(data_size());
  m__io__raw_rle_runs = new kaitai::kstream(m__raw_rle_runs);
  m_rle_runs = new rle_runs_t(m__io__raw_rle_runs, this, m__root);
}

spr_t::indexed_rle_image_t::~indexed_rle_image_t() { _clean_up(); }

void spr_t::indexed_rle_image_t::_clean_up() {
  if (m__io__raw_rle_runs) {
    delete m__io__raw_rle_runs;
    m__io__raw_rle_runs = 0;
  }
  if (m_rle_runs) {
    delete m_rle_runs;
    m_rle_runs = 0;
  }
}

spr_t::rle_run_t::rle_run_t(kaitai::kstream* p__io,
                            spr_t::rle_runs_t* p__parent, spr_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void spr_t::rle_run_t::_read() {
  m_value = m__io->read_u1();
  n_count = true;
  if (value() == 0) {
    n_count = false;
    m_count = m__io->read_u1();
  }
}

spr_t::rle_run_t::~rle_run_t() { _clean_up(); }

void spr_t::rle_run_t::_clean_up() {
  if (!n_count) {
  }
}

}  // namespace raglib
