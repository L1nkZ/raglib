#ifndef RSM_H_
#define RSM_H_

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

class rsm_t : public kaitai::kstruct {
 public:
  class texture_vertex_t;
  class face_info_t;
  class pos_key_frame_t;
  class rot_key_frame_t;
  class tex_animation_t;
  class texture_key_frame_t;
  class mesh_vertex_t;
  class node_info_t;
  class string_t;
  class volume_box_t;
  class node_t;
  class scale_key_frame_t;
  class animated_texture_t;

  enum shading_t { SHADING_NONE = 0, SHADING_FLAT = 1, SHADING_SMOOTH = 2 };

  rsm_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0,
        rsm_t* p__root = 0);

 private:
  void _read();
  void _clean_up();

 public:
  ~rsm_t();

  class texture_vertex_t : public kaitai::kstruct {
   public:
    texture_vertex_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = 0,
                     rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~texture_vertex_t();

   private:
    uint32_t m_color;
    bool n_color;

   public:
    bool _is_null_color() {
      color();
      return n_color;
    };

   private:
    std::vector<float>* m_position;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    uint32_t color() const { return m_color; }
    std::vector<float>* position() const { return m_position; }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class face_info_t : public kaitai::kstruct {
   public:
    face_info_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = 0,
                rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~face_info_t();

   private:
    int32_t m_length;
    bool n_length;

   public:
    bool _is_null_length() {
      length();
      return n_length;
    };

   private:
    std::vector<uint16_t>* m_mesh_vertex_ids;
    std::vector<uint16_t>* m_texture_vertex_ids;
    uint16_t m_texture_id;
    uint16_t m_padding;
    int32_t m_two_sides;
    int32_t m_smooth_group_x;
    bool n_smooth_group_x;

   public:
    bool _is_null_smooth_group_x() {
      smooth_group_x();
      return n_smooth_group_x;
    };

   private:
    int32_t m_smooth_group_y;
    bool n_smooth_group_y;

   public:
    bool _is_null_smooth_group_y() {
      smooth_group_y();
      return n_smooth_group_y;
    };

   private:
    int32_t m_smooth_group_z;
    bool n_smooth_group_z;

   public:
    bool _is_null_smooth_group_z() {
      smooth_group_z();
      return n_smooth_group_z;
    };

   private:
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    int32_t length() const { return m_length; }
    std::vector<uint16_t>* mesh_vertex_ids() const { return m_mesh_vertex_ids; }
    std::vector<uint16_t>* texture_vertex_ids() const {
      return m_texture_vertex_ids;
    }
    uint16_t texture_id() const { return m_texture_id; }
    uint16_t padding() const { return m_padding; }
    int32_t two_sides() const { return m_two_sides; }
    int32_t smooth_group_x() const { return m_smooth_group_x; }
    int32_t smooth_group_y() const { return m_smooth_group_y; }
    int32_t smooth_group_z() const { return m_smooth_group_z; }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class pos_key_frame_t : public kaitai::kstruct {
   public:
    pos_key_frame_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = 0,
                    rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~pos_key_frame_t();

   private:
    int32_t m_frame_id;
    std::vector<float>* m_position;
    int32_t m_data;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    int32_t frame_id() const { return m_frame_id; }
    std::vector<float>* position() const { return m_position; }
    int32_t data() const { return m_data; }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class rot_key_frame_t : public kaitai::kstruct {
   public:
    rot_key_frame_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = 0,
                    rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~rot_key_frame_t();

   private:
    int32_t m_frame_id;
    std::vector<float>* m_quaternion;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    int32_t frame_id() const { return m_frame_id; }
    std::vector<float>* quaternion() const { return m_quaternion; }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class tex_animation_t : public kaitai::kstruct {
   public:
    tex_animation_t(kaitai::kstream* p__io,
                    rsm_t::animated_texture_t* p__parent = 0,
                    rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~tex_animation_t();

   private:
    int32_t m_type;
    int32_t m_tex_frame_count;
    std::vector<texture_key_frame_t*>* m_tex_key_frames;
    rsm_t* m__root;
    rsm_t::animated_texture_t* m__parent;

   public:
    int32_t type() const { return m_type; }
    int32_t tex_frame_count() const { return m_tex_frame_count; }
    std::vector<texture_key_frame_t*>* tex_key_frames() const {
      return m_tex_key_frames;
    }
    rsm_t* _root() const { return m__root; }
    rsm_t::animated_texture_t* _parent() const { return m__parent; }
  };

  class texture_key_frame_t : public kaitai::kstruct {
   public:
    texture_key_frame_t(kaitai::kstream* p__io,
                        rsm_t::tex_animation_t* p__parent = 0,
                        rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~texture_key_frame_t();

   private:
    int32_t m_frame_id;
    float m_offset;
    rsm_t* m__root;
    rsm_t::tex_animation_t* m__parent;

   public:
    int32_t frame_id() const { return m_frame_id; }
    float offset() const { return m_offset; }
    rsm_t* _root() const { return m__root; }
    rsm_t::tex_animation_t* _parent() const { return m__parent; }
  };

  class mesh_vertex_t : public kaitai::kstruct {
   public:
    mesh_vertex_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = 0,
                  rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~mesh_vertex_t();

   private:
    std::vector<float>* m_position;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    std::vector<float>* position() const { return m_position; }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class node_info_t : public kaitai::kstruct {
   public:
    node_info_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = 0,
                rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~node_info_t();

   private:
    std::vector<float>* m_offset_matrix;
    std::vector<float>* m_offset_vector;
    std::vector<float>* m_position;
    bool n_position;

   public:
    bool _is_null_position() {
      position();
      return n_position;
    };

   private:
    float m_rotation_angle;
    bool n_rotation_angle;

   public:
    bool _is_null_rotation_angle() {
      rotation_angle();
      return n_rotation_angle;
    };

   private:
    std::vector<float>* m_rotation_axis;
    bool n_rotation_axis;

   public:
    bool _is_null_rotation_axis() {
      rotation_axis();
      return n_rotation_axis;
    };

   private:
    std::vector<float>* m_scale;
    bool n_scale;

   public:
    bool _is_null_scale() {
      scale();
      return n_scale;
    };

   private:
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    std::vector<float>* offset_matrix() const { return m_offset_matrix; }
    std::vector<float>* offset_vector() const { return m_offset_vector; }
    std::vector<float>* position() const { return m_position; }
    float rotation_angle() const { return m_rotation_angle; }
    std::vector<float>* rotation_axis() const { return m_rotation_axis; }
    std::vector<float>* scale() const { return m_scale; }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class string_t : public kaitai::kstruct {
   public:
    string_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0,
             rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~string_t();

   private:
    int32_t m_len;
    bool n_len;

   public:
    bool _is_null_len() {
      len();
      return n_len;
    };

   private:
    std::string m_value;
    rsm_t* m__root;
    kaitai::kstruct* m__parent;

   public:
    int32_t len() const { return m_len; }
    std::string value() const { return m_value; }
    rsm_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
  };

  class volume_box_t : public kaitai::kstruct {
   public:
    volume_box_t(kaitai::kstream* p__io, rsm_t* p__parent = 0,
                 rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~volume_box_t();

   private:
    std::vector<float>* m_size;
    std::vector<float>* m_position;
    std::vector<float>* m_rotation;
    int32_t m_flag;
    bool n_flag;

   public:
    bool _is_null_flag() {
      flag();
      return n_flag;
    };

   private:
    rsm_t* m__root;
    rsm_t* m__parent;

   public:
    std::vector<float>* size() const { return m_size; }
    std::vector<float>* position() const { return m_position; }
    std::vector<float>* rotation() const { return m_rotation; }
    int32_t flag() const { return m_flag; }
    rsm_t* _root() const { return m__root; }
    rsm_t* _parent() const { return m__parent; }
  };

  class node_t : public kaitai::kstruct {
   public:
    node_t(kaitai::kstream* p__io, rsm_t* p__parent = 0, rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~node_t();

   private:
    string_t* m_name;
    string_t* m_parent_name;
    int32_t m_texture_count;
    std::vector<string_t*>* m_texture_names;
    bool n_texture_names;

   public:
    bool _is_null_texture_names() {
      texture_names();
      return n_texture_names;
    };

   private:
    std::vector<int32_t>* m_texture_ids;
    bool n_texture_ids;

   public:
    bool _is_null_texture_ids() {
      texture_ids();
      return n_texture_ids;
    };

   private:
    node_info_t* m_info;
    int32_t m_mesh_vertex_count;
    std::vector<mesh_vertex_t*>* m_mesh_vertices;
    int32_t m_texture_vertex_count;
    std::vector<texture_vertex_t*>* m_texture_vertices;
    int32_t m_face_count;
    std::vector<face_info_t*>* m_faces;
    int32_t m_scale_key_count;
    bool n_scale_key_count;

   public:
    bool _is_null_scale_key_count() {
      scale_key_count();
      return n_scale_key_count;
    };

   private:
    std::vector<scale_key_frame_t*>* m_scale_key_frames;
    bool n_scale_key_frames;

   public:
    bool _is_null_scale_key_frames() {
      scale_key_frames();
      return n_scale_key_frames;
    };

   private:
    int32_t m_rot_key_count;
    std::vector<rot_key_frame_t*>* m_rot_key_frames;
    int32_t m_pos_key_count;
    bool n_pos_key_count;

   public:
    bool _is_null_pos_key_count() {
      pos_key_count();
      return n_pos_key_count;
    };

   private:
    std::vector<pos_key_frame_t*>* m_pos_key_frames;
    bool n_pos_key_frames;

   public:
    bool _is_null_pos_key_frames() {
      pos_key_frames();
      return n_pos_key_frames;
    };

   private:
    int32_t m_animated_texture_count;
    bool n_animated_texture_count;

   public:
    bool _is_null_animated_texture_count() {
      animated_texture_count();
      return n_animated_texture_count;
    };

   private:
    std::vector<animated_texture_t*>* m_animated_textures;
    bool n_animated_textures;

   public:
    bool _is_null_animated_textures() {
      animated_textures();
      return n_animated_textures;
    };

   private:
    rsm_t* m__root;
    rsm_t* m__parent;

   public:
    string_t* name() const { return m_name; }
    string_t* parent_name() const { return m_parent_name; }
    int32_t texture_count() const { return m_texture_count; }
    std::vector<string_t*>* texture_names() const { return m_texture_names; }
    std::vector<int32_t>* texture_ids() const { return m_texture_ids; }
    node_info_t* info() const { return m_info; }
    int32_t mesh_vertex_count() const { return m_mesh_vertex_count; }
    std::vector<mesh_vertex_t*>* mesh_vertices() const {
      return m_mesh_vertices;
    }
    int32_t texture_vertex_count() const { return m_texture_vertex_count; }
    std::vector<texture_vertex_t*>* texture_vertices() const {
      return m_texture_vertices;
    }
    int32_t face_count() const { return m_face_count; }
    std::vector<face_info_t*>* faces() const { return m_faces; }
    int32_t scale_key_count() const { return m_scale_key_count; }
    std::vector<scale_key_frame_t*>* scale_key_frames() const {
      return m_scale_key_frames;
    }
    int32_t rot_key_count() const { return m_rot_key_count; }
    std::vector<rot_key_frame_t*>* rot_key_frames() const {
      return m_rot_key_frames;
    }
    int32_t pos_key_count() const { return m_pos_key_count; }
    std::vector<pos_key_frame_t*>* pos_key_frames() const {
      return m_pos_key_frames;
    }
    int32_t animated_texture_count() const { return m_animated_texture_count; }
    std::vector<animated_texture_t*>* animated_textures() const {
      return m_animated_textures;
    }
    rsm_t* _root() const { return m__root; }
    rsm_t* _parent() const { return m__parent; }
  };

  class scale_key_frame_t : public kaitai::kstruct {
   public:
    scale_key_frame_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0,
                      rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~scale_key_frame_t();

   private:
    int32_t m_frame_id;
    std::vector<float>* m_scale;
    float m_data;
    rsm_t* m__root;
    kaitai::kstruct* m__parent;

   public:
    int32_t frame_id() const { return m_frame_id; }
    std::vector<float>* scale() const { return m_scale; }
    float data() const { return m_data; }
    rsm_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
  };

  class animated_texture_t : public kaitai::kstruct {
   public:
    animated_texture_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = 0,
                       rsm_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~animated_texture_t();

   private:
    int32_t m_texture_id;
    int32_t m_animation_count;
    std::vector<tex_animation_t*>* m_tex_animations;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    int32_t texture_id() const { return m_texture_id; }
    int32_t animation_count() const { return m_animation_count; }
    std::vector<tex_animation_t*>* tex_animations() const {
      return m_tex_animations;
    }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

 private:
  std::string m_magic;
  uint16_t m_version;
  int32_t m_animation_count;
  shading_t m_shading_type;
  uint8_t m_alpha;
  bool n_alpha;

 public:
  bool _is_null_alpha() {
    alpha();
    return n_alpha;
  };

 private:
  std::string m_reserved;
  bool n_reserved;

 public:
  bool _is_null_reserved() {
    reserved();
    return n_reserved;
  };

 private:
  float m_frame_rate_per_second;
  bool n_frame_rate_per_second;

 public:
  bool _is_null_frame_rate_per_second() {
    frame_rate_per_second();
    return n_frame_rate_per_second;
  };

 private:
  int32_t m_texture_count;
  bool n_texture_count;

 public:
  bool _is_null_texture_count() {
    texture_count();
    return n_texture_count;
  };

 private:
  std::vector<string_t*>* m_texture_names;
  bool n_texture_names;

 public:
  bool _is_null_texture_names() {
    texture_names();
    return n_texture_names;
  };

 private:
  int32_t m_root_node_count;
  bool n_root_node_count;

 public:
  bool _is_null_root_node_count() {
    root_node_count();
    return n_root_node_count;
  };

 private:
  std::vector<string_t*>* m_root_node_names;
  bool n_root_node_names;

 public:
  bool _is_null_root_node_names() {
    root_node_names();
    return n_root_node_names;
  };

 private:
  string_t* m_root_node_name;
  bool n_root_node_name;

 public:
  bool _is_null_root_node_name() {
    root_node_name();
    return n_root_node_name;
  };

 private:
  int32_t m_node_count;
  std::vector<node_t*>* m_nodes;
  int32_t m_scale_key_count;
  bool n_scale_key_count;

 public:
  bool _is_null_scale_key_count() {
    scale_key_count();
    return n_scale_key_count;
  };

 private:
  std::vector<scale_key_frame_t*>* m_scale_key_frames;
  bool n_scale_key_frames;

 public:
  bool _is_null_scale_key_frames() {
    scale_key_frames();
    return n_scale_key_frames;
  };

 private:
  int32_t m_volume_box_count;
  bool n_volume_box_count;

 public:
  bool _is_null_volume_box_count() {
    volume_box_count();
    return n_volume_box_count;
  };

 private:
  std::vector<volume_box_t*>* m_volume_boxes;
  bool n_volume_boxes;

 public:
  bool _is_null_volume_boxes() {
    volume_boxes();
    return n_volume_boxes;
  };

 private:
  rsm_t* m__root;
  kaitai::kstruct* m__parent;

 public:
  /**
   * File identification, must be "GRSM".
   */
  std::string magic() const { return m_magic; }
  uint16_t version() const { return m_version; }
  int32_t animation_count() const { return m_animation_count; }
  shading_t shading_type() const { return m_shading_type; }
  uint8_t alpha() const { return m_alpha; }
  std::string reserved() const { return m_reserved; }
  float frame_rate_per_second() const { return m_frame_rate_per_second; }
  int32_t texture_count() const { return m_texture_count; }
  std::vector<string_t*>* texture_names() const { return m_texture_names; }
  int32_t root_node_count() const { return m_root_node_count; }
  std::vector<string_t*>* root_node_names() const { return m_root_node_names; }
  string_t* root_node_name() const { return m_root_node_name; }
  int32_t node_count() const { return m_node_count; }
  std::vector<node_t*>* nodes() const { return m_nodes; }
  int32_t scale_key_count() const { return m_scale_key_count; }
  std::vector<scale_key_frame_t*>* scale_key_frames() const {
    return m_scale_key_frames;
  }
  int32_t volume_box_count() const { return m_volume_box_count; }
  std::vector<volume_box_t*>* volume_boxes() const { return m_volume_boxes; }
  rsm_t* _root() const { return m__root; }
  kaitai::kstruct* _parent() const { return m__parent; }
};

}  // namespace raglib

#endif  // RSM_H_
