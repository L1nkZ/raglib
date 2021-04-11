// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include "raglib/rsm.h"

#include "kaitai/exceptions.h"

namespace raglib {

rsm_t::rsm_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = this;
  m_texture_names = 0;
  m_root_node_names = 0;
  m_root_node_name = 0;
  m_nodes = 0;
  m_scale_key_frames = 0;
  m_volume_boxes = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::_read() {
  m_magic = m__io->read_bytes(4);
  if (!(magic() == std::string("\x47\x52\x53\x4D", 4))) {
    throw kaitai::validation_not_equal_error<std::string>(
        std::string("\x47\x52\x53\x4D", 4), magic(), _io(),
        std::string("/seq/0"));
  }
  m_version = m__io->read_u2be();
  m_animation_count = m__io->read_s4le();
  m_shading_type = static_cast<rsm_t::shading_t>(m__io->read_s4le());
  n_alpha = true;
  if (_root()->version() >= 260) {
    n_alpha = false;
    m_alpha = m__io->read_u1();
  }
  n_reserved = true;
  if (_root()->version() < 512) {
    n_reserved = false;
    m_reserved = m__io->read_bytes(16);
  }
  n_frame_rate_per_second = true;
  if (_root()->version() >= 514) {
    n_frame_rate_per_second = false;
    m_frame_rate_per_second = m__io->read_f4le();
  }
  n_texture_count = true;
  if (_root()->version() <= 514) {
    n_texture_count = false;
    m_texture_count = m__io->read_s4le();
    {
      int32_t _ = texture_count();
      if (!(_ <= 1024)) {
        throw kaitai::validation_expr_error<int32_t>(texture_count(), _io(),
                                                     std::string("/seq/7"));
      }
    }
  }
  n_texture_names = true;
  if (_root()->version() <= 514) {
    n_texture_names = false;
    int l_texture_names = texture_count();
    m_texture_names = new std::vector<string_t*>();
    m_texture_names->reserve(l_texture_names);
    for (int i = 0; i < l_texture_names; i++) {
      m_texture_names->push_back(new string_t(m__io, this, m__root));
    }
  }
  n_root_node_count = true;
  if (_root()->version() >= 514) {
    n_root_node_count = false;
    m_root_node_count = m__io->read_s4le();
    {
      int32_t _ = root_node_count();
      if (!(_ <= 1024)) {
        throw kaitai::validation_expr_error<int32_t>(root_node_count(), _io(),
                                                     std::string("/seq/9"));
      }
    }
  }
  n_root_node_names = true;
  if (_root()->version() >= 514) {
    n_root_node_names = false;
    int l_root_node_names = root_node_count();
    m_root_node_names = new std::vector<string_t*>();
    m_root_node_names->reserve(l_root_node_names);
    for (int i = 0; i < l_root_node_names; i++) {
      m_root_node_names->push_back(new string_t(m__io, this, m__root));
    }
  }
  n_root_node_name = true;
  if (_root()->version() < 512) {
    n_root_node_name = false;
    m_root_node_name = new string_t(m__io, this, m__root);
  }
  m_node_count = m__io->read_s4le();
  {
    int32_t _ = node_count();
    if (!(_ <= 1024)) {
      throw kaitai::validation_expr_error<int32_t>(node_count(), _io(),
                                                   std::string("/seq/12"));
    }
  }
  int l_nodes = node_count();
  m_nodes = new std::vector<node_t*>();
  m_nodes->reserve(l_nodes);
  for (int i = 0; i < l_nodes; i++) {
    m_nodes->push_back(new node_t(m__io, this, m__root));
  }
  n_scale_key_count = true;
  if (_root()->version() < 262) {
    n_scale_key_count = false;
    m_scale_key_count = m__io->read_s4le();
    {
      int32_t _ = scale_key_count();
      if (!(_ <= 65536)) {
        throw kaitai::validation_expr_error<int32_t>(scale_key_count(), _io(),
                                                     std::string("/seq/14"));
      }
    }
  }
  n_scale_key_frames = true;
  if (_root()->version() < 262) {
    n_scale_key_frames = false;
    int l_scale_key_frames = scale_key_count();
    m_scale_key_frames = new std::vector<scale_key_frame_t*>();
    m_scale_key_frames->reserve(l_scale_key_frames);
    for (int i = 0; i < l_scale_key_frames; i++) {
      m_scale_key_frames->push_back(
          new scale_key_frame_t(m__io, this, m__root));
    }
  }
  n_volume_box_count = true;
  if (!(_io()->is_eof())) {
    n_volume_box_count = false;
    m_volume_box_count = m__io->read_s4le();
    {
      int32_t _ = volume_box_count();
      if (!(_ <= 65536)) {
        throw kaitai::validation_expr_error<int32_t>(volume_box_count(), _io(),
                                                     std::string("/seq/16"));
      }
    }
  }
  n_volume_boxes = true;
  if (!(_io()->is_eof())) {
    n_volume_boxes = false;
    int l_volume_boxes = volume_box_count();
    m_volume_boxes = new std::vector<volume_box_t*>();
    m_volume_boxes->reserve(l_volume_boxes);
    for (int i = 0; i < l_volume_boxes; i++) {
      m_volume_boxes->push_back(new volume_box_t(m__io, this, m__root));
    }
  }
}

rsm_t::~rsm_t() { _clean_up(); }

void rsm_t::_clean_up() {
  if (!n_alpha) {
  }
  if (!n_reserved) {
  }
  if (!n_frame_rate_per_second) {
  }
  if (!n_texture_count) {
  }
  if (!n_texture_names) {
    if (m_texture_names) {
      for (std::vector<string_t*>::iterator it = m_texture_names->begin();
           it != m_texture_names->end(); ++it) {
        delete *it;
      }
      delete m_texture_names;
      m_texture_names = 0;
    }
  }
  if (!n_root_node_count) {
  }
  if (!n_root_node_names) {
    if (m_root_node_names) {
      for (std::vector<string_t*>::iterator it = m_root_node_names->begin();
           it != m_root_node_names->end(); ++it) {
        delete *it;
      }
      delete m_root_node_names;
      m_root_node_names = 0;
    }
  }
  if (!n_root_node_name) {
    if (m_root_node_name) {
      delete m_root_node_name;
      m_root_node_name = 0;
    }
  }
  if (m_nodes) {
    for (std::vector<node_t*>::iterator it = m_nodes->begin();
         it != m_nodes->end(); ++it) {
      delete *it;
    }
    delete m_nodes;
    m_nodes = 0;
  }
  if (!n_scale_key_count) {
  }
  if (!n_scale_key_frames) {
    if (m_scale_key_frames) {
      for (std::vector<scale_key_frame_t*>::iterator it =
               m_scale_key_frames->begin();
           it != m_scale_key_frames->end(); ++it) {
        delete *it;
      }
      delete m_scale_key_frames;
      m_scale_key_frames = 0;
    }
  }
  if (!n_volume_box_count) {
  }
  if (!n_volume_boxes) {
    if (m_volume_boxes) {
      for (std::vector<volume_box_t*>::iterator it = m_volume_boxes->begin();
           it != m_volume_boxes->end(); ++it) {
        delete *it;
      }
      delete m_volume_boxes;
      m_volume_boxes = 0;
    }
  }
}

rsm_t::texture_vertex_t::texture_vertex_t(kaitai::kstream* p__io,
                                          rsm_t::node_t* p__parent,
                                          rsm_t* p__root)
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

void rsm_t::texture_vertex_t::_read() {
  n_color = true;
  if (_root()->version() >= 258) {
    n_color = false;
    m_color = m__io->read_u4le();
  }
  int l_position = 2;
  m_position = new std::vector<float>();
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(m__io->read_f4le());
  }
}

rsm_t::texture_vertex_t::~texture_vertex_t() { _clean_up(); }

void rsm_t::texture_vertex_t::_clean_up() {
  if (!n_color) {
  }
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
}

rsm_t::face_info_t::face_info_t(kaitai::kstream* p__io,
                                rsm_t::node_t* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_mesh_vertex_ids = 0;
  m_texture_vertex_ids = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::face_info_t::_read() {
  n_length = true;
  if (_root()->version() >= 514) {
    n_length = false;
    m_length = m__io->read_s4le();
  }
  int l_mesh_vertex_ids = 3;
  m_mesh_vertex_ids = new std::vector<uint16_t>();
  m_mesh_vertex_ids->reserve(l_mesh_vertex_ids);
  for (int i = 0; i < l_mesh_vertex_ids; i++) {
    m_mesh_vertex_ids->push_back(m__io->read_u2le());
  }
  int l_texture_vertex_ids = 3;
  m_texture_vertex_ids = new std::vector<uint16_t>();
  m_texture_vertex_ids->reserve(l_texture_vertex_ids);
  for (int i = 0; i < l_texture_vertex_ids; i++) {
    m_texture_vertex_ids->push_back(m__io->read_u2le());
  }
  m_texture_id = m__io->read_u2le();
  m_padding = m__io->read_u2le();
  m_two_sides = m__io->read_s4le();
  n_smooth_group_x = true;
  if (_root()->version() >= 258) {
    n_smooth_group_x = false;
    m_smooth_group_x = m__io->read_s4le();
  }
  n_smooth_group_y = true;
  if (((_root()->version() >= 514) && (length() > 24))) {
    n_smooth_group_y = false;
    m_smooth_group_y = m__io->read_s4le();
  }
  n_smooth_group_z = true;
  if (((_root()->version() >= 514) && (length() > 28))) {
    n_smooth_group_z = false;
    m_smooth_group_z = m__io->read_s4le();
  }
}

rsm_t::face_info_t::~face_info_t() { _clean_up(); }

void rsm_t::face_info_t::_clean_up() {
  if (!n_length) {
  }
  if (m_mesh_vertex_ids) {
    delete m_mesh_vertex_ids;
    m_mesh_vertex_ids = 0;
  }
  if (m_texture_vertex_ids) {
    delete m_texture_vertex_ids;
    m_texture_vertex_ids = 0;
  }
  if (!n_smooth_group_x) {
  }
  if (!n_smooth_group_y) {
  }
  if (!n_smooth_group_z) {
  }
}

rsm_t::pos_key_frame_t::pos_key_frame_t(kaitai::kstream* p__io,
                                        rsm_t::node_t* p__parent,
                                        rsm_t* p__root)
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

void rsm_t::pos_key_frame_t::_read() {
  m_frame_id = m__io->read_s4le();
  int l_position = 3;
  m_position = new std::vector<float>();
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(m__io->read_f4le());
  }
  m_data = m__io->read_s4le();
}

rsm_t::pos_key_frame_t::~pos_key_frame_t() { _clean_up(); }

void rsm_t::pos_key_frame_t::_clean_up() {
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
}

rsm_t::rot_key_frame_t::rot_key_frame_t(kaitai::kstream* p__io,
                                        rsm_t::node_t* p__parent,
                                        rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_quaternion = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::rot_key_frame_t::_read() {
  m_frame_id = m__io->read_s4le();
  int l_quaternion = 4;
  m_quaternion = new std::vector<float>();
  m_quaternion->reserve(l_quaternion);
  for (int i = 0; i < l_quaternion; i++) {
    m_quaternion->push_back(m__io->read_f4le());
  }
}

rsm_t::rot_key_frame_t::~rot_key_frame_t() { _clean_up(); }

void rsm_t::rot_key_frame_t::_clean_up() {
  if (m_quaternion) {
    delete m_quaternion;
    m_quaternion = 0;
  }
}

rsm_t::tex_animation_t::tex_animation_t(kaitai::kstream* p__io,
                                        rsm_t::animated_texture_t* p__parent,
                                        rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_tex_key_frames = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::tex_animation_t::_read() {
  m_type = m__io->read_s4le();
  m_tex_frame_count = m__io->read_s4le();
  {
    int32_t _ = tex_frame_count();
    if (!(_ <= 65536)) {
      throw kaitai::validation_expr_error<int32_t>(
          tex_frame_count(), _io(), std::string("/types/tex_animation/seq/1"));
    }
  }
  int l_tex_key_frames = tex_frame_count();
  m_tex_key_frames = new std::vector<texture_key_frame_t*>();
  m_tex_key_frames->reserve(l_tex_key_frames);
  for (int i = 0; i < l_tex_key_frames; i++) {
    m_tex_key_frames->push_back(new texture_key_frame_t(m__io, this, m__root));
  }
}

rsm_t::tex_animation_t::~tex_animation_t() { _clean_up(); }

void rsm_t::tex_animation_t::_clean_up() {
  if (m_tex_key_frames) {
    for (std::vector<texture_key_frame_t*>::iterator it =
             m_tex_key_frames->begin();
         it != m_tex_key_frames->end(); ++it) {
      delete *it;
    }
    delete m_tex_key_frames;
    m_tex_key_frames = 0;
  }
}

rsm_t::texture_key_frame_t::texture_key_frame_t(
    kaitai::kstream* p__io, rsm_t::tex_animation_t* p__parent, rsm_t* p__root)
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

void rsm_t::texture_key_frame_t::_read() {
  m_frame_id = m__io->read_s4le();
  m_offset = m__io->read_f4le();
}

rsm_t::texture_key_frame_t::~texture_key_frame_t() { _clean_up(); }

void rsm_t::texture_key_frame_t::_clean_up() {}

rsm_t::mesh_vertex_t::mesh_vertex_t(kaitai::kstream* p__io,
                                    rsm_t::node_t* p__parent, rsm_t* p__root)
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

void rsm_t::mesh_vertex_t::_read() {
  int l_position = 3;
  m_position = new std::vector<float>();
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(m__io->read_f4le());
  }
}

rsm_t::mesh_vertex_t::~mesh_vertex_t() { _clean_up(); }

void rsm_t::mesh_vertex_t::_clean_up() {
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
}

rsm_t::node_info_t::node_info_t(kaitai::kstream* p__io,
                                rsm_t::node_t* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_offset_matrix = 0;
  m_offset_vector = 0;
  m_position = 0;
  m_rotation_axis = 0;
  m_scale = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::node_info_t::_read() {
  int l_offset_matrix = 9;
  m_offset_matrix = new std::vector<float>();
  m_offset_matrix->reserve(l_offset_matrix);
  for (int i = 0; i < l_offset_matrix; i++) {
    m_offset_matrix->push_back(m__io->read_f4le());
  }
  int l_offset_vector = 3;
  m_offset_vector = new std::vector<float>();
  m_offset_vector->reserve(l_offset_vector);
  for (int i = 0; i < l_offset_vector; i++) {
    m_offset_vector->push_back(m__io->read_f4le());
  }
  n_position = true;
  if (_root()->version() < 514) {
    n_position = false;
    int l_position = 3;
    m_position = new std::vector<float>();
    m_position->reserve(l_position);
    for (int i = 0; i < l_position; i++) {
      m_position->push_back(m__io->read_f4le());
    }
  }
  n_rotation_angle = true;
  if (_root()->version() < 514) {
    n_rotation_angle = false;
    m_rotation_angle = m__io->read_f4le();
  }
  n_rotation_axis = true;
  if (_root()->version() < 514) {
    n_rotation_axis = false;
    int l_rotation_axis = 3;
    m_rotation_axis = new std::vector<float>();
    m_rotation_axis->reserve(l_rotation_axis);
    for (int i = 0; i < l_rotation_axis; i++) {
      m_rotation_axis->push_back(m__io->read_f4le());
    }
  }
  n_scale = true;
  if (_root()->version() < 514) {
    n_scale = false;
    int l_scale = 3;
    m_scale = new std::vector<float>();
    m_scale->reserve(l_scale);
    for (int i = 0; i < l_scale; i++) {
      m_scale->push_back(m__io->read_f4le());
    }
  }
}

rsm_t::node_info_t::~node_info_t() { _clean_up(); }

void rsm_t::node_info_t::_clean_up() {
  if (m_offset_matrix) {
    delete m_offset_matrix;
    m_offset_matrix = 0;
  }
  if (m_offset_vector) {
    delete m_offset_vector;
    m_offset_vector = 0;
  }
  if (!n_position) {
    if (m_position) {
      delete m_position;
      m_position = 0;
    }
  }
  if (!n_rotation_angle) {
  }
  if (!n_rotation_axis) {
    if (m_rotation_axis) {
      delete m_rotation_axis;
      m_rotation_axis = 0;
    }
  }
  if (!n_scale) {
    if (m_scale) {
      delete m_scale;
      m_scale = 0;
    }
  }
}

rsm_t::string_t::string_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent,
                          rsm_t* p__root)
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

void rsm_t::string_t::_read() {
  n_len = true;
  if (_root()->version() > 512) {
    n_len = false;
    m_len = m__io->read_s4le();
    {
      int32_t _ = len();
      if (!(_ <= 1024)) {
        throw kaitai::validation_expr_error<int32_t>(
            len(), _io(), std::string("/types/string/seq/0"));
      }
    }
  }
  m_value = m__io->read_bytes(((_root()->version() > 512) ? (len()) : (40)));
}

rsm_t::string_t::~string_t() { _clean_up(); }

void rsm_t::string_t::_clean_up() {
  if (!n_len) {
  }
}

rsm_t::volume_box_t::volume_box_t(kaitai::kstream* p__io, rsm_t* p__parent,
                                  rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_size = 0;
  m_position = 0;
  m_rotation = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::volume_box_t::_read() {
  int l_size = 3;
  m_size = new std::vector<float>();
  m_size->reserve(l_size);
  for (int i = 0; i < l_size; i++) {
    m_size->push_back(m__io->read_f4le());
  }
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
  n_flag = true;
  if (_root()->version() >= 259) {
    n_flag = false;
    m_flag = m__io->read_s4le();
  }
}

rsm_t::volume_box_t::~volume_box_t() { _clean_up(); }

void rsm_t::volume_box_t::_clean_up() {
  if (m_size) {
    delete m_size;
    m_size = 0;
  }
  if (m_position) {
    delete m_position;
    m_position = 0;
  }
  if (m_rotation) {
    delete m_rotation;
    m_rotation = 0;
  }
  if (!n_flag) {
  }
}

rsm_t::node_t::node_t(kaitai::kstream* p__io, rsm_t* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_name = 0;
  m_parent_name = 0;
  m_texture_names = 0;
  m_texture_ids = 0;
  m_info = 0;
  m_mesh_vertices = 0;
  m_texture_vertices = 0;
  m_faces = 0;
  m_scale_key_frames = 0;
  m_rot_key_frames = 0;
  m_pos_key_frames = 0;
  m_animated_textures = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::node_t::_read() {
  m_name = new string_t(m__io, this, m__root);
  m_parent_name = new string_t(m__io, this, m__root);
  m_texture_count = m__io->read_s4le();
  {
    int32_t _ = texture_count();
    if (!(_ <= 1024)) {
      throw kaitai::validation_expr_error<int32_t>(
          texture_count(), _io(), std::string("/types/node/seq/2"));
    }
  }
  n_texture_names = true;
  if (_root()->version() >= 515) {
    n_texture_names = false;
    int l_texture_names = texture_count();
    m_texture_names = new std::vector<string_t*>();
    m_texture_names->reserve(l_texture_names);
    for (int i = 0; i < l_texture_names; i++) {
      m_texture_names->push_back(new string_t(m__io, this, m__root));
    }
  }
  n_texture_ids = true;
  if (_root()->version() < 515) {
    n_texture_ids = false;
    int l_texture_ids = texture_count();
    m_texture_ids = new std::vector<int32_t>();
    m_texture_ids->reserve(l_texture_ids);
    for (int i = 0; i < l_texture_ids; i++) {
      m_texture_ids->push_back(m__io->read_s4le());
    }
  }
  m_info = new node_info_t(m__io, this, m__root);
  m_mesh_vertex_count = m__io->read_s4le();
  {
    int32_t _ = mesh_vertex_count();
    if (!(_ <= 65536)) {
      throw kaitai::validation_expr_error<int32_t>(
          mesh_vertex_count(), _io(), std::string("/types/node/seq/6"));
    }
  }
  int l_mesh_vertices = mesh_vertex_count();
  m_mesh_vertices = new std::vector<mesh_vertex_t*>();
  m_mesh_vertices->reserve(l_mesh_vertices);
  for (int i = 0; i < l_mesh_vertices; i++) {
    m_mesh_vertices->push_back(new mesh_vertex_t(m__io, this, m__root));
  }
  m_texture_vertex_count = m__io->read_s4le();
  {
    int32_t _ = texture_vertex_count();
    if (!(_ <= 65536)) {
      throw kaitai::validation_expr_error<int32_t>(
          texture_vertex_count(), _io(), std::string("/types/node/seq/8"));
    }
  }
  int l_texture_vertices = texture_vertex_count();
  m_texture_vertices = new std::vector<texture_vertex_t*>();
  m_texture_vertices->reserve(l_texture_vertices);
  for (int i = 0; i < l_texture_vertices; i++) {
    m_texture_vertices->push_back(new texture_vertex_t(m__io, this, m__root));
  }
  m_face_count = m__io->read_s4le();
  {
    int32_t _ = face_count();
    if (!(_ <= 65536)) {
      throw kaitai::validation_expr_error<int32_t>(
          face_count(), _io(), std::string("/types/node/seq/10"));
    }
  }
  int l_faces = face_count();
  m_faces = new std::vector<face_info_t*>();
  m_faces->reserve(l_faces);
  for (int i = 0; i < l_faces; i++) {
    m_faces->push_back(new face_info_t(m__io, this, m__root));
  }
  n_scale_key_count = true;
  if (_root()->version() >= 262) {
    n_scale_key_count = false;
    m_scale_key_count = m__io->read_s4le();
    {
      int32_t _ = scale_key_count();
      if (!(_ <= 65536)) {
        throw kaitai::validation_expr_error<int32_t>(
            scale_key_count(), _io(), std::string("/types/node/seq/12"));
      }
    }
  }
  n_scale_key_frames = true;
  if (_root()->version() >= 262) {
    n_scale_key_frames = false;
    int l_scale_key_frames = scale_key_count();
    m_scale_key_frames = new std::vector<scale_key_frame_t*>();
    m_scale_key_frames->reserve(l_scale_key_frames);
    for (int i = 0; i < l_scale_key_frames; i++) {
      m_scale_key_frames->push_back(
          new scale_key_frame_t(m__io, this, m__root));
    }
  }
  m_rot_key_count = m__io->read_s4le();
  {
    int32_t _ = rot_key_count();
    if (!(_ <= 65536)) {
      throw kaitai::validation_expr_error<int32_t>(
          rot_key_count(), _io(), std::string("/types/node/seq/14"));
    }
  }
  int l_rot_key_frames = rot_key_count();
  m_rot_key_frames = new std::vector<rot_key_frame_t*>();
  m_rot_key_frames->reserve(l_rot_key_frames);
  for (int i = 0; i < l_rot_key_frames; i++) {
    m_rot_key_frames->push_back(new rot_key_frame_t(m__io, this, m__root));
  }
  n_pos_key_count = true;
  if (_root()->version() >= 514) {
    n_pos_key_count = false;
    m_pos_key_count = m__io->read_s4le();
    {
      int32_t _ = pos_key_count();
      if (!(_ <= 65536)) {
        throw kaitai::validation_expr_error<int32_t>(
            pos_key_count(), _io(), std::string("/types/node/seq/16"));
      }
    }
  }
  n_pos_key_frames = true;
  if (_root()->version() >= 514) {
    n_pos_key_frames = false;
    int l_pos_key_frames = pos_key_count();
    m_pos_key_frames = new std::vector<pos_key_frame_t*>();
    m_pos_key_frames->reserve(l_pos_key_frames);
    for (int i = 0; i < l_pos_key_frames; i++) {
      m_pos_key_frames->push_back(new pos_key_frame_t(m__io, this, m__root));
    }
  }
  n_animated_texture_count = true;
  if (_root()->version() >= 515) {
    n_animated_texture_count = false;
    m_animated_texture_count = m__io->read_s4le();
    {
      int32_t _ = animated_texture_count();
      if (!(_ <= 65536)) {
        throw kaitai::validation_expr_error<int32_t>(
            animated_texture_count(), _io(), std::string("/types/node/seq/18"));
      }
    }
  }
  n_animated_textures = true;
  if (_root()->version() >= 515) {
    n_animated_textures = false;
    int l_animated_textures = animated_texture_count();
    m_animated_textures = new std::vector<animated_texture_t*>();
    m_animated_textures->reserve(l_animated_textures);
    for (int i = 0; i < l_animated_textures; i++) {
      m_animated_textures->push_back(
          new animated_texture_t(m__io, this, m__root));
    }
  }
}

rsm_t::node_t::~node_t() { _clean_up(); }

void rsm_t::node_t::_clean_up() {
  if (m_name) {
    delete m_name;
    m_name = 0;
  }
  if (m_parent_name) {
    delete m_parent_name;
    m_parent_name = 0;
  }
  if (!n_texture_names) {
    if (m_texture_names) {
      for (std::vector<string_t*>::iterator it = m_texture_names->begin();
           it != m_texture_names->end(); ++it) {
        delete *it;
      }
      delete m_texture_names;
      m_texture_names = 0;
    }
  }
  if (!n_texture_ids) {
    if (m_texture_ids) {
      delete m_texture_ids;
      m_texture_ids = 0;
    }
  }
  if (m_info) {
    delete m_info;
    m_info = 0;
  }
  if (m_mesh_vertices) {
    for (std::vector<mesh_vertex_t*>::iterator it = m_mesh_vertices->begin();
         it != m_mesh_vertices->end(); ++it) {
      delete *it;
    }
    delete m_mesh_vertices;
    m_mesh_vertices = 0;
  }
  if (m_texture_vertices) {
    for (std::vector<texture_vertex_t*>::iterator it =
             m_texture_vertices->begin();
         it != m_texture_vertices->end(); ++it) {
      delete *it;
    }
    delete m_texture_vertices;
    m_texture_vertices = 0;
  }
  if (m_faces) {
    for (std::vector<face_info_t*>::iterator it = m_faces->begin();
         it != m_faces->end(); ++it) {
      delete *it;
    }
    delete m_faces;
    m_faces = 0;
  }
  if (!n_scale_key_count) {
  }
  if (!n_scale_key_frames) {
    if (m_scale_key_frames) {
      for (std::vector<scale_key_frame_t*>::iterator it =
               m_scale_key_frames->begin();
           it != m_scale_key_frames->end(); ++it) {
        delete *it;
      }
      delete m_scale_key_frames;
      m_scale_key_frames = 0;
    }
  }
  if (m_rot_key_frames) {
    for (std::vector<rot_key_frame_t*>::iterator it = m_rot_key_frames->begin();
         it != m_rot_key_frames->end(); ++it) {
      delete *it;
    }
    delete m_rot_key_frames;
    m_rot_key_frames = 0;
  }
  if (!n_pos_key_count) {
  }
  if (!n_pos_key_frames) {
    if (m_pos_key_frames) {
      for (std::vector<pos_key_frame_t*>::iterator it =
               m_pos_key_frames->begin();
           it != m_pos_key_frames->end(); ++it) {
        delete *it;
      }
      delete m_pos_key_frames;
      m_pos_key_frames = 0;
    }
  }
  if (!n_animated_texture_count) {
  }
  if (!n_animated_textures) {
    if (m_animated_textures) {
      for (std::vector<animated_texture_t*>::iterator it =
               m_animated_textures->begin();
           it != m_animated_textures->end(); ++it) {
        delete *it;
      }
      delete m_animated_textures;
      m_animated_textures = 0;
    }
  }
}

rsm_t::scale_key_frame_t::scale_key_frame_t(kaitai::kstream* p__io,
                                            kaitai::kstruct* p__parent,
                                            rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_scale = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::scale_key_frame_t::_read() {
  m_frame_id = m__io->read_s4le();
  int l_scale = 3;
  m_scale = new std::vector<float>();
  m_scale->reserve(l_scale);
  for (int i = 0; i < l_scale; i++) {
    m_scale->push_back(m__io->read_f4le());
  }
  m_data = m__io->read_f4le();
}

rsm_t::scale_key_frame_t::~scale_key_frame_t() { _clean_up(); }

void rsm_t::scale_key_frame_t::_clean_up() {
  if (m_scale) {
    delete m_scale;
    m_scale = 0;
  }
}

rsm_t::animated_texture_t::animated_texture_t(kaitai::kstream* p__io,
                                              rsm_t::node_t* p__parent,
                                              rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_tex_animations = 0;

  try {
    _read();
  } catch (...) {
    _clean_up();
    throw;
  }
}

void rsm_t::animated_texture_t::_read() {
  m_texture_id = m__io->read_s4le();
  m_animation_count = m__io->read_s4le();
  {
    int32_t _ = animation_count();
    if (!(_ <= 65536)) {
      throw kaitai::validation_expr_error<int32_t>(
          animation_count(), _io(),
          std::string("/types/animated_texture/seq/1"));
    }
  }
  int l_tex_animations = animation_count();
  m_tex_animations = new std::vector<tex_animation_t*>();
  m_tex_animations->reserve(l_tex_animations);
  for (int i = 0; i < l_tex_animations; i++) {
    m_tex_animations->push_back(new tex_animation_t(m__io, this, m__root));
  }
}

rsm_t::animated_texture_t::~animated_texture_t() { _clean_up(); }

void rsm_t::animated_texture_t::_clean_up() {
  if (m_tex_animations) {
    for (std::vector<tex_animation_t*>::iterator it = m_tex_animations->begin();
         it != m_tex_animations->end(); ++it) {
      delete *it;
    }
    delete m_tex_animations;
    m_tex_animations = 0;
  }
}

}  // namespace raglib
