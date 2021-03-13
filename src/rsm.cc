// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include "raglib/rsm.h"

#include "kaitai/exceptions.h"
namespace raglib {

rsm_t::rsm_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = this;
  m_texture_names = nullptr;
  m_nodes = nullptr;
  m_pos_key_frames = nullptr;
  m_volume_boxes = nullptr;
  _read();
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
  m_alpha = m__io->read_u1();
  m_reserved = m__io->read_bytes(16);
  m_texture_count = m__io->read_s4le();
  int l_texture_names = texture_count();
  m_texture_names =
      std::unique_ptr<std::vector<std::string>>(new std::vector<std::string>());
  m_texture_names->reserve(l_texture_names);
  for (int i = 0; i < l_texture_names; i++) {
    m_texture_names->push_back(std::move(m__io->read_bytes(40)));
  }
  m_main_node_name = m__io->read_bytes(40);
  m_node_count = m__io->read_s4le();
  int l_nodes = node_count();
  m_nodes = std::unique_ptr<std::vector<std::unique_ptr<node_t>>>(
      new std::vector<std::unique_ptr<node_t>>());
  m_nodes->reserve(l_nodes);
  for (int i = 0; i < l_nodes; i++) {
    m_nodes->push_back(
        std::move(std::unique_ptr<node_t>(new node_t(m__io, this, m__root))));
  }
  n_pos_key_count = true;
  if (_root()->version() < 261) {
    n_pos_key_count = false;
    m_pos_key_count = m__io->read_s4le();
  }
  n_pos_key_frames = true;
  if (_root()->version() < 261) {
    n_pos_key_frames = false;
    int l_pos_key_frames = pos_key_count();
    m_pos_key_frames =
        std::unique_ptr<std::vector<std::unique_ptr<pos_key_frame_t>>>(
            new std::vector<std::unique_ptr<pos_key_frame_t>>());
    m_pos_key_frames->reserve(l_pos_key_frames);
    for (int i = 0; i < l_pos_key_frames; i++) {
      m_pos_key_frames->push_back(std::move(std::unique_ptr<pos_key_frame_t>(
          new pos_key_frame_t(m__io, this, m__root))));
    }
  }
  m_volume_box_count = m__io->read_s4le();
  int l_volume_boxes = volume_box_count();
  m_volume_boxes = std::unique_ptr<std::vector<std::unique_ptr<volume_box_t>>>(
      new std::vector<std::unique_ptr<volume_box_t>>());
  m_volume_boxes->reserve(l_volume_boxes);
  for (int i = 0; i < l_volume_boxes; i++) {
    m_volume_boxes->push_back(std::move(
        std::unique_ptr<volume_box_t>(new volume_box_t(m__io, this, m__root))));
  }
}

rsm_t::~rsm_t() { _clean_up(); }

void rsm_t::_clean_up() {
  if (!n_pos_key_count) {
  }
  if (!n_pos_key_frames) {
  }
}

rsm_t::texture_vertex_t::texture_vertex_t(kaitai::kstream* p__io,
                                          rsm_t::node_t* p__parent,
                                          rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_position = nullptr;
  _read();
}

void rsm_t::texture_vertex_t::_read() {
  n_color = true;
  if (_root()->version() >= 258) {
    n_color = false;
    m_color = m__io->read_u4le();
  }
  int l_position = 2;
  m_position = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(std::move(m__io->read_f4le()));
  }
}

rsm_t::texture_vertex_t::~texture_vertex_t() { _clean_up(); }

void rsm_t::texture_vertex_t::_clean_up() {
  if (!n_color) {
  }
}

rsm_t::face_info_t::face_info_t(kaitai::kstream* p__io,
                                rsm_t::node_t* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_node_vertex_ids = nullptr;
  m_texture_vertex_ids = nullptr;
  _read();
}

void rsm_t::face_info_t::_read() {
  int l_node_vertex_ids = 3;
  m_node_vertex_ids =
      std::unique_ptr<std::vector<uint16_t>>(new std::vector<uint16_t>());
  m_node_vertex_ids->reserve(l_node_vertex_ids);
  for (int i = 0; i < l_node_vertex_ids; i++) {
    m_node_vertex_ids->push_back(std::move(m__io->read_u2le()));
  }
  int l_texture_vertex_ids = 3;
  m_texture_vertex_ids =
      std::unique_ptr<std::vector<uint16_t>>(new std::vector<uint16_t>());
  m_texture_vertex_ids->reserve(l_texture_vertex_ids);
  for (int i = 0; i < l_texture_vertex_ids; i++) {
    m_texture_vertex_ids->push_back(std::move(m__io->read_u2le()));
  }
  m_texture_id = m__io->read_u2le();
  m_padding = m__io->read_u2le();
  m_two_sides = m__io->read_s4le();
  n_smooth_group = true;
  if (_root()->version() >= 258) {
    n_smooth_group = false;
    m_smooth_group = m__io->read_s4le();
  }
}

rsm_t::face_info_t::~face_info_t() { _clean_up(); }

void rsm_t::face_info_t::_clean_up() {
  if (!n_smooth_group) {
  }
}

rsm_t::pos_key_frame_t::pos_key_frame_t(kaitai::kstream* p__io,
                                        kaitai::kstruct* p__parent,
                                        rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_position = nullptr;
  _read();
}

void rsm_t::pos_key_frame_t::_read() {
  m_frame_id = m__io->read_s4le();
  int l_position = 3;
  m_position = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(std::move(m__io->read_f4le()));
  }
}

rsm_t::pos_key_frame_t::~pos_key_frame_t() { _clean_up(); }

void rsm_t::pos_key_frame_t::_clean_up() {}

rsm_t::rot_key_frame_t::rot_key_frame_t(kaitai::kstream* p__io,
                                        rsm_t::node_t* p__parent,
                                        rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_quaternion = nullptr;
  _read();
}

void rsm_t::rot_key_frame_t::_read() {
  m_frame_id = m__io->read_s4le();
  int l_quaternion = 4;
  m_quaternion = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_quaternion->reserve(l_quaternion);
  for (int i = 0; i < l_quaternion; i++) {
    m_quaternion->push_back(std::move(m__io->read_f4le()));
  }
}

rsm_t::rot_key_frame_t::~rot_key_frame_t() { _clean_up(); }

void rsm_t::rot_key_frame_t::_clean_up() {}

rsm_t::node_info_t::node_info_t(kaitai::kstream* p__io,
                                rsm_t::node_t* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_offset_matrix = nullptr;
  m_offset_vector = nullptr;
  m_position = nullptr;
  m_rotation_axis = nullptr;
  m_scale = nullptr;
  _read();
}

void rsm_t::node_info_t::_read() {
  int l_offset_matrix = 9;
  m_offset_matrix =
      std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_offset_matrix->reserve(l_offset_matrix);
  for (int i = 0; i < l_offset_matrix; i++) {
    m_offset_matrix->push_back(std::move(m__io->read_f4le()));
  }
  int l_offset_vector = 3;
  m_offset_vector =
      std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_offset_vector->reserve(l_offset_vector);
  for (int i = 0; i < l_offset_vector; i++) {
    m_offset_vector->push_back(std::move(m__io->read_f4le()));
  }
  int l_position = 3;
  m_position = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(std::move(m__io->read_f4le()));
  }
  m_rotation_angle = m__io->read_f4le();
  int l_rotation_axis = 3;
  m_rotation_axis =
      std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_rotation_axis->reserve(l_rotation_axis);
  for (int i = 0; i < l_rotation_axis; i++) {
    m_rotation_axis->push_back(std::move(m__io->read_f4le()));
  }
  int l_scale = 3;
  m_scale = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_scale->reserve(l_scale);
  for (int i = 0; i < l_scale; i++) {
    m_scale->push_back(std::move(m__io->read_f4le()));
  }
}

rsm_t::node_info_t::~node_info_t() { _clean_up(); }

void rsm_t::node_info_t::_clean_up() {}

rsm_t::volume_box_t::volume_box_t(kaitai::kstream* p__io, rsm_t* p__parent,
                                  rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_size = nullptr;
  m_position = nullptr;
  m_rotation = nullptr;
  _read();
}

void rsm_t::volume_box_t::_read() {
  int l_size = 3;
  m_size = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_size->reserve(l_size);
  for (int i = 0; i < l_size; i++) {
    m_size->push_back(std::move(m__io->read_f4le()));
  }
  int l_position = 3;
  m_position = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(std::move(m__io->read_f4le()));
  }
  int l_rotation = 3;
  m_rotation = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_rotation->reserve(l_rotation);
  for (int i = 0; i < l_rotation; i++) {
    m_rotation->push_back(std::move(m__io->read_f4le()));
  }
  n_flag = true;
  if (_root()->version() >= 259) {
    n_flag = false;
    m_flag = m__io->read_s4le();
  }
}

rsm_t::volume_box_t::~volume_box_t() { _clean_up(); }

void rsm_t::volume_box_t::_clean_up() {
  if (!n_flag) {
  }
}

rsm_t::node_vertex_t::node_vertex_t(kaitai::kstream* p__io,
                                    rsm_t::node_t* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_position = nullptr;
  _read();
}

void rsm_t::node_vertex_t::_read() {
  int l_position = 3;
  m_position = std::unique_ptr<std::vector<float>>(new std::vector<float>());
  m_position->reserve(l_position);
  for (int i = 0; i < l_position; i++) {
    m_position->push_back(std::move(m__io->read_f4le()));
  }
}

rsm_t::node_vertex_t::~node_vertex_t() { _clean_up(); }

void rsm_t::node_vertex_t::_clean_up() {}

rsm_t::node_t::node_t(kaitai::kstream* p__io, rsm_t* p__parent, rsm_t* p__root)
    : kaitai::kstruct(p__io) {
  m__parent = p__parent;
  m__root = p__root;
  m_texture_ids = nullptr;
  m_info = nullptr;
  m_node_vertices = nullptr;
  m_texture_vertices = nullptr;
  m_faces_info = nullptr;
  m_pos_key_frames = nullptr;
  m_rot_key_frames = nullptr;
  _read();
}

void rsm_t::node_t::_read() {
  m_name = m__io->read_bytes(40);
  m_parent_name = m__io->read_bytes(40);
  m_texture_count = m__io->read_s4le();
  int l_texture_ids = texture_count();
  m_texture_ids =
      std::unique_ptr<std::vector<int32_t>>(new std::vector<int32_t>());
  m_texture_ids->reserve(l_texture_ids);
  for (int i = 0; i < l_texture_ids; i++) {
    m_texture_ids->push_back(std::move(m__io->read_s4le()));
  }
  m_info = std::unique_ptr<node_info_t>(new node_info_t(m__io, this, m__root));
  m_node_vertex_count = m__io->read_s4le();
  int l_node_vertices = node_vertex_count();
  m_node_vertices =
      std::unique_ptr<std::vector<std::unique_ptr<node_vertex_t>>>(
          new std::vector<std::unique_ptr<node_vertex_t>>());
  m_node_vertices->reserve(l_node_vertices);
  for (int i = 0; i < l_node_vertices; i++) {
    m_node_vertices->push_back(std::move(std::unique_ptr<node_vertex_t>(
        new node_vertex_t(m__io, this, m__root))));
  }
  m_texture_vertex_count = m__io->read_s4le();
  int l_texture_vertices = texture_vertex_count();
  m_texture_vertices =
      std::unique_ptr<std::vector<std::unique_ptr<texture_vertex_t>>>(
          new std::vector<std::unique_ptr<texture_vertex_t>>());
  m_texture_vertices->reserve(l_texture_vertices);
  for (int i = 0; i < l_texture_vertices; i++) {
    m_texture_vertices->push_back(std::move(std::unique_ptr<texture_vertex_t>(
        new texture_vertex_t(m__io, this, m__root))));
  }
  m_face_count = m__io->read_s4le();
  int l_faces_info = face_count();
  m_faces_info = std::unique_ptr<std::vector<std::unique_ptr<face_info_t>>>(
      new std::vector<std::unique_ptr<face_info_t>>());
  m_faces_info->reserve(l_faces_info);
  for (int i = 0; i < l_faces_info; i++) {
    m_faces_info->push_back(std::move(
        std::unique_ptr<face_info_t>(new face_info_t(m__io, this, m__root))));
  }
  n_pos_key_count = true;
  if (_root()->version() >= 261) {
    n_pos_key_count = false;
    m_pos_key_count = m__io->read_s4le();
  }
  n_pos_key_frames = true;
  if (_root()->version() >= 261) {
    n_pos_key_frames = false;
    int l_pos_key_frames = pos_key_count();
    m_pos_key_frames =
        std::unique_ptr<std::vector<std::unique_ptr<pos_key_frame_t>>>(
            new std::vector<std::unique_ptr<pos_key_frame_t>>());
    m_pos_key_frames->reserve(l_pos_key_frames);
    for (int i = 0; i < l_pos_key_frames; i++) {
      m_pos_key_frames->push_back(std::move(std::unique_ptr<pos_key_frame_t>(
          new pos_key_frame_t(m__io, this, m__root))));
    }
  }
  m_rot_key_count = m__io->read_s4le();
  int l_rot_key_frames = rot_key_count();
  m_rot_key_frames =
      std::unique_ptr<std::vector<std::unique_ptr<rot_key_frame_t>>>(
          new std::vector<std::unique_ptr<rot_key_frame_t>>());
  m_rot_key_frames->reserve(l_rot_key_frames);
  for (int i = 0; i < l_rot_key_frames; i++) {
    m_rot_key_frames->push_back(std::move(std::unique_ptr<rot_key_frame_t>(
        new rot_key_frame_t(m__io, this, m__root))));
  }
}

rsm_t::node_t::~node_t() { _clean_up(); }

void rsm_t::node_t::_clean_up() {
  if (!n_pos_key_count) {
  }
  if (!n_pos_key_frames) {
  }
}
}  // namespace raglib
