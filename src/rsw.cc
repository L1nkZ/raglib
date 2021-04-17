// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include "raglib/rsw.h"

#include "kaitai/exceptions.h"

namespace raglib {

rsw_t::rsw_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rsw_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = this;
  m_water_info = 0;
  m_light_info = 0;
  m_ground_info = 0;
  m_objects = 0;
  m_quad_tree_nodes = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsw_t::_read() {
  m_magic = m__io->read_bytes(4);
  if (!(magic() == std::string("\x47\x52\x53\x57", 4))) {
    throw kaitai::validation_not_equal_error<std::string>(
        std::string("\x47\x52\x53\x57", 4), magic(), _io(),
        std::string("/seq/0"));
  }
  m_version = m__io->read_u2be();
  m_ini_file_name = m__io->read_bytes(40);
  m_gnd_file_name = m__io->read_bytes(40);
  m_gat_file_name = m__io->read_bytes(40);
  n_src_file_name = true;
  if (version() >= 260) {
    n_src_file_name = false;
    m_src_file_name = m__io->read_bytes(40);
  }
  n_water_info = true;
  if (version() >= 259) {
    n_water_info = false;
    m_water_info = new water_t(m__io, this, m__root);
  }
  n_light_info = true;
  if (version() >= 261) {
    n_light_info = false;
    m_light_info = new light_t(m__io, this, m__root);
  }
  n_ground_info = true;
  if (version() >= 262) {
    n_ground_info = false;
    m_ground_info = new ground_t(m__io, this, m__root);
  }
  m_object_count = m__io->read_s4le();
  {
    int32_t _ = object_count();
    if (!(_ <= 65536)) {
      throw kaitai::validation_expr_error<int32_t>(object_count(), _io(),
                                                   std::string("/seq/9"));
    }
  }
  int l_objects = object_count();
  m_objects = new std::vector<object_t*>();
  m_objects->reserve(l_objects);
  for (int i = 0; i < l_objects; i++) {
    m_objects->push_back(new object_t(m__io, this, m__root));
  }
  m_quad_tree_nodes = new std::vector<quad_tree_node_t*>();
  {
    int i = 0;
    while (!m__io->is_eof()) {
      m_quad_tree_nodes->push_back(new quad_tree_node_t(m__io, this, m__root));
      i++;
    }
  }
}

rsw_t::~rsw_t() { _clean_up(); }

void rsw_t::_clean_up() {
  if (!n_src_file_name) {
  }
  if (!n_water_info) {
    if (m_water_info) {
      delete m_water_info;
      m_water_info = 0;
    }
  }
  if (!n_light_info) {
    if (m_light_info) {
      delete m_light_info;
      m_light_info = 0;
    }
  }
  if (!n_ground_info) {
    if (m_ground_info) {
      delete m_ground_info;
      m_ground_info = 0;
    }
  }
  if (m_objects) {
    for (std::vector<object_t*>::iterator it = m_objects->begin();
         it != m_objects->end(); ++it) {
      delete *it;
    }
    delete m_objects;
    m_objects = 0;
  }
  if (m_quad_tree_nodes) {
    for (std::vector<quad_tree_node_t*>::iterator it =
             m_quad_tree_nodes->begin();
         it != m_quad_tree_nodes->end(); ++it) {
      delete *it;
    }
    delete m_quad_tree_nodes;
    m_quad_tree_nodes = 0;
  }
}

rsw_t::sound_obj_t::sound_obj_t(kaitai::kstream* p__io,
                                rsw_t::object_t* p__parent, rsw_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_position = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsw_t::sound_obj_t::_read() {
  m_name = m__io->read_bytes(80);
  m_file_name = m__io->read_bytes(80);
  int l_position = 3;
  m_position = new std::vector<float>();
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(m__io->read_f4le());
  }
  m_volume = m__io->read_f4le();
  m_width = m__io->read_s4le();
  m_height = m__io->read_s4le();
  m_range = m__io->read_f4le();
  n_cycle = true;
  if (_root()->version() >= 512) {
    n_cycle = false;
    m_cycle = m__io->read_f4le();
  }
}

rsw_t::sound_obj_t::~sound_obj_t() { _clean_up(); }

void rsw_t::sound_obj_t::_clean_up() {
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
  if (!n_cycle) {
  }
}

rsw_t::light_obj_t::light_obj_t(kaitai::kstream* p__io,
                                rsw_t::object_t* p__parent, rsw_t* p__root)
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

void rsw_t::light_obj_t::_read() {
  m_name = m__io->read_bytes(80);
  int l_position = 3;
  m_position = new std::vector<float>();
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(m__io->read_f4le());
  }
  int l_color = 3;
  m_color = new std::vector<int32_t>();
  m_color->reserve(l_color);
  for (int i = 0; i < l_color; i++) {
    m_color->push_back(m__io->read_s4le());
  }
  m_range = m__io->read_f4le();
}

rsw_t::light_obj_t::~light_obj_t() { _clean_up(); }

void rsw_t::light_obj_t::_clean_up() {
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
  if (m_color) {
    delete m_color;
    m_color = 0;
  }
}

rsw_t::effect_obj_t::effect_obj_t(kaitai::kstream* p__io,
                                  rsw_t::object_t* p__parent, rsw_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_position = 0;
  m_param = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsw_t::effect_obj_t::_read() {
  m_name = m__io->read_bytes(80);
  int l_position = 3;
  m_position = new std::vector<float>();
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(m__io->read_f4le());
  }
  m_id = m__io->read_s4le();
  m_delay = m__io->read_f4le();
  int l_param = 4;
  m_param = new std::vector<float>();
  m_param->reserve(l_param);
  for (int i = 0; i < l_param; i++) {
    m_param->push_back(m__io->read_f4le());
  }
}

rsw_t::effect_obj_t::~effect_obj_t() { _clean_up(); }

void rsw_t::effect_obj_t::_clean_up() {
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
  if (m_param) {
    delete m_param;
    m_param = 0;
  }
}

rsw_t::object_t::object_t(kaitai::kstream* p__io, rsw_t* p__parent,
                          rsw_t* p__root)
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

void rsw_t::object_t::_read() {
  n_value = true;
  m_type = m__io->read_s4le();
  {
    int32_t _ = type();
    if (!(((_ >= 1) && (_ <= 4)))) {
      throw kaitai::validation_expr_error<int32_t>(
          type(), _io(), std::string("/types/object/seq/0"));
    }
  }
  
  switch (type()) {
    case 1: {
      m_value = new model_obj_t(m__io, this, m__root);
      n_value = false;
      break;
    }
    case 2: {
      m_value = new light_obj_t(m__io, this, m__root);
      n_value = false;
      break;
    }
    case 3: {
      m_value = new sound_obj_t(m__io, this, m__root);
      n_value = false;
      break;
    }
    case 4: {
      m_value = new effect_obj_t(m__io, this, m__root);
      n_value = false;
      break;
    }
  }
}

rsw_t::object_t::~object_t() { _clean_up(); }

void rsw_t::object_t::_clean_up() {
  if (!n_value) {
    if (m_value) {
      delete m_value;
      m_value = 0;
    }
  }
}

rsw_t::water_t::water_t(kaitai::kstream* p__io, rsw_t* p__parent,
                        rsw_t* p__root)
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

void rsw_t::water_t::_read() {
  m_level = m__io->read_f4le();
  n_type = true;
  if (_root()->version() >= 264) {
    n_type = false;
    m_type = m__io->read_s4le();
  }
  n_wave_height = true;
  if (_root()->version() >= 264) {
    n_wave_height = false;
    m_wave_height = m__io->read_f4le();
  }
  n_wave_speed = true;
  if (_root()->version() >= 264) {
    n_wave_speed = false;
    m_wave_speed = m__io->read_f4le();
  }
  n_wave_pitch = true;
  if (_root()->version() >= 264) {
    n_wave_pitch = false;
    m_wave_pitch = m__io->read_f4le();
  }
  n_animation_speed = true;
  if (_root()->version() >= 264) {
    n_animation_speed = false;
    m_animation_speed = m__io->read_f4le();
  }
}

rsw_t::water_t::~water_t() { _clean_up(); }

void rsw_t::water_t::_clean_up() {
  if (!n_type) {
  }
  if (!n_wave_height) {
  }
  if (!n_wave_speed) {
  }
  if (!n_wave_pitch) {
  }
  if (!n_animation_speed) {
  }
}

rsw_t::ground_t::ground_t(kaitai::kstream* p__io, rsw_t* p__parent,
                          rsw_t* p__root)
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

void rsw_t::ground_t::_read() {
  m_top = m__io->read_s4le();
  m_bottom = m__io->read_s4le();
  m_left = m__io->read_s4le();
  m_right = m__io->read_s4le();
}

rsw_t::ground_t::~ground_t() { _clean_up(); }

void rsw_t::ground_t::_clean_up() {}

rsw_t::model_obj_t::model_obj_t(kaitai::kstream* p__io,
                                rsw_t::object_t* p__parent, rsw_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_position = 0;
  m_rotation = 0;
  m_scale = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsw_t::model_obj_t::_read() {
  n_name = true;
  if (_root()->version() >= 259) {
    n_name = false;
    m_name = m__io->read_bytes(40);
  }
  n_animation_type = true;
  if (_root()->version() >= 259) {
    n_animation_type = false;
    m_animation_type = m__io->read_s4le();
  }
  n_animation_speed = true;
  if (_root()->version() >= 259) {
    n_animation_speed = false;
    m_animation_speed = m__io->read_f4le();
  }
  n_block_type = true;
  if (_root()->version() >= 259) {
    n_block_type = false;
    m_block_type = m__io->read_s4le();
  }
  m_file_name = m__io->read_bytes(80);
  m_node_name = m__io->read_bytes(80);
  int l_position = 3;
  m_position = new std::vector<float>();
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(m__io->read_f4le());
  }
  int l_rotation = 3;
  m_rotation = new std::vector<float>();
  m_rotation->reserve(l_rotation);
  for (int i = 0; i < l_rotation; i++) {
    m_rotation->push_back(m__io->read_f4le());
  }
  int l_scale = 3;
  m_scale = new std::vector<float>();
  m_scale->reserve(l_scale);
  for (int i = 0; i < l_scale; i++) {
    m_scale->push_back(m__io->read_f4le());
  }
}

rsw_t::model_obj_t::~model_obj_t() { _clean_up(); }

void rsw_t::model_obj_t::_clean_up() {
  if (!n_name) {
  }
  if (!n_animation_type) {
  }
  if (!n_animation_speed) {
  }
  if (!n_block_type) {
  }
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
  if (m_rotation) {
    delete m_rotation;
    m_rotation = 0;
  }
  if (m_scale) {
    delete m_scale;
    m_scale = 0;
  }
}

rsw_t::quad_tree_node_t::quad_tree_node_t(kaitai::kstream* p__io,
                                          rsw_t* p__parent, rsw_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_max = 0;
  m_min = 0;
  m_half_size = 0;
  m_center = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsw_t::quad_tree_node_t::_read() {
  int l_max = 3;
  m_max = new std::vector<float>();
  m_max->reserve(l_max);
  for (int i = 0; i < l_max; i++) {
    m_max->push_back(m__io->read_f4le());
  }
  int l_min = 3;
  m_min = new std::vector<float>();
  m_min->reserve(l_min);
  for (int i = 0; i < l_min; i++) {
    m_min->push_back(m__io->read_f4le());
  }
  int l_half_size = 3;
  m_half_size = new std::vector<float>();
  m_half_size->reserve(l_half_size);
  for (int i = 0; i < l_half_size; i++) {
    m_half_size->push_back(m__io->read_f4le());
  }
  int l_center = 3;
  m_center = new std::vector<float>();
  m_center->reserve(l_center);
  for (int i = 0; i < l_center; i++) {
    m_center->push_back(m__io->read_f4le());
  }
}

rsw_t::quad_tree_node_t::~quad_tree_node_t() { _clean_up(); }

void rsw_t::quad_tree_node_t::_clean_up() {
  if (m_max) {
    delete m_max;
    m_max = 0;
  }
  if (m_min) {
    delete m_min;
    m_min = 0;
  }
  if (m_half_size) {
    delete m_half_size;
    m_half_size = 0;
  }
  if (m_center) {
    delete m_center;
    m_center = 0;
  }
}

rsw_t::light_t::light_t(kaitai::kstream* p__io, rsw_t* p__parent,
                        rsw_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_diffuse = 0;
  m_ambient = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsw_t::light_t::_read() {
  m_longitude = m__io->read_s4le();
  m_latitude = m__io->read_s4le();
  int l_diffuse = 3;
  m_diffuse = new std::vector<float>();
  m_diffuse->reserve(l_diffuse);
  for (int i = 0; i < l_diffuse; i++) {
    m_diffuse->push_back(m__io->read_f4le());
  }
  int l_ambient = 3;
  m_ambient = new std::vector<float>();
  m_ambient->reserve(l_ambient);
  for (int i = 0; i < l_ambient; i++) {
    m_ambient->push_back(m__io->read_f4le());
  }
  n_opacity = true;
  if (_root()->version() >= 263) {
    n_opacity = false;
    m_opacity = m__io->read_f4le();
  }
}

rsw_t::light_t::~light_t() { _clean_up(); }

void rsw_t::light_t::_clean_up() {
  if (m_diffuse) {
    delete m_diffuse;
    m_diffuse = 0;
  }
  if (m_ambient) {
    delete m_ambient;
    m_ambient = 0;
  }
  if (!n_opacity) {
  }
}

}  // namespace raglib
