// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include "raglib/act.h"

#include "kaitai/exceptions.h"

namespace raglib {

act_t::act_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, act_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = this;
  m_actions = 0;
  m_sound_files = 0;
  m_animation_speeds = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void act_t::_read() {
  m_magic = m__io->read_bytes(2);
  if (!(magic() == std::string("\x41\x43", 2))) {
    throw kaitai::validation_not_equal_error<std::string>(
        std::string("\x41\x43", 2), magic(), _io(), std::string("/seq/0"));
  }
  m_version = m__io->read_u2le();
  m_action_count = m__io->read_u2le();
  {
    uint16_t _ = action_count();
    if (!(_ <= 256)) {
      throw kaitai::validation_expr_error<uint16_t>(action_count(), _io(),
                                                    std::string("/seq/2"));
    }
  }
  m_unknown = m__io->read_bytes(10);
  int l_actions = action_count();
  m_actions = new std::vector<action_t*>();
  m_actions->reserve(l_actions);
  for (int i = 0; i < l_actions; i++) {
    m_actions->push_back(new action_t(m__io, this, m__root));
  }
  n_sound_file_count = true;
  if (version() >= 513) {
    n_sound_file_count = false;
    m_sound_file_count = m__io->read_s4le();
    {
      int32_t _ = sound_file_count();
      if (!(_ <= 256)) {
        throw kaitai::validation_expr_error<int32_t>(sound_file_count(), _io(),
                                                     std::string("/seq/5"));
      }
    }
  }
  n_sound_files = true;
  if (version() >= 513) {
    n_sound_files = false;
    int l_sound_files = sound_file_count();
    m_sound_files = new std::vector<std::string>();
    m_sound_files->reserve(l_sound_files);
    for (int i = 0; i < l_sound_files; i++) {
      m_sound_files->push_back(m__io->read_bytes(40));
    }
  }
  n_animation_speeds = true;
  if (version() >= 514) {
    n_animation_speeds = false;
    m_animation_speeds = new std::vector<float>();
    {
      int i = 0;
      while (!m__io->is_eof()) {
        m_animation_speeds->push_back(m__io->read_f4le());
        i++;
      }
    }
  }
}

act_t::~act_t() { _clean_up(); }

void act_t::_clean_up() {
  if (m_actions) {
    for (std::vector<action_t*>::iterator it = m_actions->begin();
         it != m_actions->end(); ++it) {
      delete *it;
    }
    delete m_actions;
    m_actions = 0;
  }
  if (!n_sound_file_count) {
  }
  if (!n_sound_files) {
    if (m_sound_files) {
      delete m_sound_files;
      m_sound_files = 0;
    }
  }
  if (!n_animation_speeds) {
    if (m_animation_speeds) {
      delete m_animation_speeds;
      m_animation_speeds = 0;
    }
  }
}

act_t::action_t::action_t(kaitai::kstream* p__io, act_t* p__parent,
                          act_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_frames = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void act_t::action_t::_read() {
  m_frame_count = m__io->read_u4le();
  {
    uint32_t _ = frame_count();
    if (!(_ <= 256)) {
      throw kaitai::validation_expr_error<uint32_t>(
          frame_count(), _io(), std::string("/types/action/seq/0"));
    }
  }
  int l_frames = frame_count();
  m_frames = new std::vector<frame_t*>();
  m_frames->reserve(l_frames);
  for (int i = 0; i < l_frames; i++) {
    m_frames->push_back(new frame_t(m__io, this, m__root));
  }
}

act_t::action_t::~action_t() { _clean_up(); }

void act_t::action_t::_clean_up() {
  if (m_frames) {
    for (std::vector<frame_t*>::iterator it = m_frames->begin();
         it != m_frames->end(); ++it) {
      delete *it;
    }
    delete m_frames;
    m_frames = 0;
  }
}

act_t::frame_t::frame_t(kaitai::kstream* p__io, act_t::action_t* p__parent,
                        act_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_layers = 0;
  m_anchors = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void act_t::frame_t::_read() {
  m_unknown = m__io->read_bytes(32);
  m_layer_count = m__io->read_u4le();
  {
    uint32_t _ = layer_count();
    if (!(_ <= 256)) {
      throw kaitai::validation_expr_error<uint32_t>(
          layer_count(), _io(), std::string("/types/frame/seq/1"));
    }
  }
  int l_layers = layer_count();
  m_layers = new std::vector<layer_t*>();
  m_layers->reserve(l_layers);
  for (int i = 0; i < l_layers; i++) {
    m_layers->push_back(new layer_t(m__io, this, m__root));
  }
  n_sound_id = true;
  if (_root()->version() >= 512) {
    n_sound_id = false;
    m_sound_id = m__io->read_s4le();
  }
  n_anchor_count = true;
  if (_root()->version() >= 515) {
    n_anchor_count = false;
    m_anchor_count = m__io->read_s4le();
    {
      int32_t _ = anchor_count();
      if (!(_ <= 256)) {
        throw kaitai::validation_expr_error<int32_t>(
            anchor_count(), _io(), std::string("/types/frame/seq/4"));
      }
    }
  }
  n_anchors = true;
  if (_root()->version() >= 515) {
    n_anchors = false;
    int l_anchors = anchor_count();
    m_anchors = new std::vector<anchor_t*>();
    m_anchors->reserve(l_anchors);
    for (int i = 0; i < l_anchors; i++) {
      m_anchors->push_back(new anchor_t(m__io, this, m__root));
    }
  }
}

act_t::frame_t::~frame_t() { _clean_up(); }

void act_t::frame_t::_clean_up() {
  if (m_layers) {
    for (std::vector<layer_t*>::iterator it = m_layers->begin();
         it != m_layers->end(); ++it) {
      delete *it;
    }
    delete m_layers;
    m_layers = 0;
  }
  if (!n_sound_id) {
  }
  if (!n_anchor_count) {
  }
  if (!n_anchors) {
    if (m_anchors) {
      for (std::vector<anchor_t*>::iterator it = m_anchors->begin();
           it != m_anchors->end(); ++it) {
        delete *it;
      }
      delete m_anchors;
      m_anchors = 0;
    }
  }
}

act_t::layer_t::layer_t(kaitai::kstream* p__io, act_t::frame_t* p__parent,
                        act_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_position = 0;
  m_color = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void act_t::layer_t::_read() {
  int l_position = 2;
  m_position = new std::vector<int32_t>();
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(m__io->read_s4le());
  }
  m_index = m__io->read_s4le();
  m_is_mirror = m__io->read_s4le();
  n_color = true;
  if (_root()->version() >= 512) {
    n_color = false;
    int l_color = 4;
    m_color = new std::vector<uint8_t>();
    m_color->reserve(l_color);
    for (int i = 0; i < l_color; i++) {
      m_color->push_back(m__io->read_u1());
    }
  }
  n_scale_x = true;
  if (_root()->version() >= 512) {
    n_scale_x = false;
    m_scale_x = m__io->read_f4le();
  }
  n_scale_y = true;
  if (_root()->version() >= 516) {
    n_scale_y = false;
    m_scale_y = m__io->read_f4le();
  }
  n_angle = true;
  if (_root()->version() >= 512) {
    n_angle = false;
    m_angle = m__io->read_s4le();
  }
  n_spr_type = true;
  if (_root()->version() >= 512) {
    n_spr_type = false;
    m_spr_type = m__io->read_s4le();
  }
  n_width = true;
  if (_root()->version() >= 517) {
    n_width = false;
    m_width = m__io->read_s4le();
  }
  n_height = true;
  if (_root()->version() >= 517) {
    n_height = false;
    m_height = m__io->read_s4le();
  }
}

act_t::layer_t::~layer_t() { _clean_up(); }

void act_t::layer_t::_clean_up() {
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
  if (!n_color) {
    if (m_color) {
      delete m_color;
      m_color = 0;
    }
  }
  if (!n_scale_x) {
  }
  if (!n_scale_y) {
  }
  if (!n_angle) {
  }
  if (!n_spr_type) {
  }
  if (!n_width) {
  }
  if (!n_height) {
  }
}

act_t::anchor_t::anchor_t(kaitai::kstream* p__io, act_t::frame_t* p__parent,
                          act_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_offset = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void act_t::anchor_t::_read() {
  m_unknown1 = m__io->read_bytes(4);
  int l_offset = 2;
  m_offset = new std::vector<int32_t>();
  m_offset->reserve(l_offset);
  for (int i = 0; i < l_offset; i++) {
    m_offset->push_back(m__io->read_s4le());
  }
  m_unknown2 = m__io->read_bytes(4);
}

act_t::anchor_t::~anchor_t() { _clean_up(); }

void act_t::anchor_t::_clean_up() {
  if (m_offset) {
    delete m_offset;
    m_offset = 0;
  }
}

}  // namespace raglib
