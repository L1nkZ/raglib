#pragma once

// This is a generated file! Please edit source .ksy file and use
// kaitai-struct-compiler to rebuild

#include <stdint.h>

#include <memory>
#include <vector>

#include "kaitai/kaitaistruct.h"

#if KAITAI_STRUCT_VERSION < 9000L
#error \
    "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif
namespace raglib {

class rsm_t : public kaitai::kstruct {
 public:
  class texture_vertex_t;
  class face_info_t;
  class pos_key_frame_t;
  class rot_key_frame_t;
  class node_info_t;
  class volume_box_t;
  class node_vertex_t;
  class node_t;

  enum shading_t { SHADING_NONE = 0, SHADING_FLAT = 1, SHADING_SMOOTH = 2 };

  rsm_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr,
        rsm_t* p__root = nullptr);

 private:
  void _read();
  void _clean_up();

 public:
  ~rsm_t();

  class texture_vertex_t : public kaitai::kstruct {
   public:
    texture_vertex_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = nullptr,
                     rsm_t* p__root = nullptr);

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
    std::unique_ptr<std::vector<float>> m_position;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    uint32_t color() const { return m_color; }
    std::vector<float>* position() const { return m_position.get(); }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class face_info_t : public kaitai::kstruct {
   public:
    face_info_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = nullptr,
                rsm_t* p__root = nullptr);

   private:
    void _read();
    void _clean_up();

   public:
    ~face_info_t();

   private:
    std::unique_ptr<std::vector<uint16_t>> m_node_vertex_ids;
    std::unique_ptr<std::vector<uint16_t>> m_texture_vertex_ids;
    uint16_t m_texture_id;
    uint16_t m_padding;
    int32_t m_two_sides;
    int32_t m_smooth_group;
    bool n_smooth_group;

   public:
    bool _is_null_smooth_group() {
      smooth_group();
      return n_smooth_group;
    };

   private:
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    std::vector<uint16_t>* node_vertex_ids() const {
      return m_node_vertex_ids.get();
    }
    std::vector<uint16_t>* texture_vertex_ids() const {
      return m_texture_vertex_ids.get();
    }
    uint16_t texture_id() const { return m_texture_id; }
    uint16_t padding() const { return m_padding; }
    int32_t two_sides() const { return m_two_sides; }
    int32_t smooth_group() const { return m_smooth_group; }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class pos_key_frame_t : public kaitai::kstruct {
   public:
    pos_key_frame_t(kaitai::kstream* p__io,
                    kaitai::kstruct* p__parent = nullptr,
                    rsm_t* p__root = nullptr);

   private:
    void _read();
    void _clean_up();

   public:
    ~pos_key_frame_t();

   private:
    int32_t m_frame_id;
    std::unique_ptr<std::vector<float>> m_position;
    rsm_t* m__root;
    kaitai::kstruct* m__parent;

   public:
    int32_t frame_id() const { return m_frame_id; }
    std::vector<float>* position() const { return m_position.get(); }
    rsm_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
  };

  class rot_key_frame_t : public kaitai::kstruct {
   public:
    rot_key_frame_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = nullptr,
                    rsm_t* p__root = nullptr);

   private:
    void _read();
    void _clean_up();

   public:
    ~rot_key_frame_t();

   private:
    int32_t m_frame_id;
    std::unique_ptr<std::vector<float>> m_quaternion;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    int32_t frame_id() const { return m_frame_id; }
    std::vector<float>* quaternion() const { return m_quaternion.get(); }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class node_info_t : public kaitai::kstruct {
   public:
    node_info_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = nullptr,
                rsm_t* p__root = nullptr);

   private:
    void _read();
    void _clean_up();

   public:
    ~node_info_t();

   private:
    std::unique_ptr<std::vector<float>> m_offset_matrix;
    std::unique_ptr<std::vector<float>> m_offset_vector;
    std::unique_ptr<std::vector<float>> m_position;
    float m_rotation_angle;
    std::unique_ptr<std::vector<float>> m_rotation_axis;
    std::unique_ptr<std::vector<float>> m_scale;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    std::vector<float>* offset_matrix() const { return m_offset_matrix.get(); }
    std::vector<float>* offset_vector() const { return m_offset_vector.get(); }
    std::vector<float>* position() const { return m_position.get(); }
    float rotation_angle() const { return m_rotation_angle; }
    std::vector<float>* rotation_axis() const { return m_rotation_axis.get(); }
    std::vector<float>* scale() const { return m_scale.get(); }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class volume_box_t : public kaitai::kstruct {
   public:
    volume_box_t(kaitai::kstream* p__io, rsm_t* p__parent = nullptr,
                 rsm_t* p__root = nullptr);

   private:
    void _read();
    void _clean_up();

   public:
    ~volume_box_t();

   private:
    std::unique_ptr<std::vector<float>> m_size;
    std::unique_ptr<std::vector<float>> m_position;
    std::unique_ptr<std::vector<float>> m_rotation;
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
    std::vector<float>* size() const { return m_size.get(); }
    std::vector<float>* position() const { return m_position.get(); }
    std::vector<float>* rotation() const { return m_rotation.get(); }
    int32_t flag() const { return m_flag; }
    rsm_t* _root() const { return m__root; }
    rsm_t* _parent() const { return m__parent; }
  };

  class node_vertex_t : public kaitai::kstruct {
   public:
    node_vertex_t(kaitai::kstream* p__io, rsm_t::node_t* p__parent = nullptr,
                  rsm_t* p__root = nullptr);

   private:
    void _read();
    void _clean_up();

   public:
    ~node_vertex_t();

   private:
    std::unique_ptr<std::vector<float>> m_position;
    rsm_t* m__root;
    rsm_t::node_t* m__parent;

   public:
    std::vector<float>* position() const { return m_position.get(); }
    rsm_t* _root() const { return m__root; }
    rsm_t::node_t* _parent() const { return m__parent; }
  };

  class node_t : public kaitai::kstruct {
   public:
    node_t(kaitai::kstream* p__io, rsm_t* p__parent = nullptr,
           rsm_t* p__root = nullptr);

   private:
    void _read();
    void _clean_up();

   public:
    ~node_t();

   private:
    std::string m_name;
    std::string m_parent_name;
    int32_t m_texture_count;
    std::unique_ptr<std::vector<int32_t>> m_texture_ids;
    std::unique_ptr<node_info_t> m_info;
    int32_t m_node_vertex_count;
    std::unique_ptr<std::vector<std::unique_ptr<node_vertex_t>>>
        m_node_vertices;
    int32_t m_texture_vertex_count;
    std::unique_ptr<std::vector<std::unique_ptr<texture_vertex_t>>>
        m_texture_vertices;
    int32_t m_face_count;
    std::unique_ptr<std::vector<std::unique_ptr<face_info_t>>> m_faces_info;
    int32_t m_pos_key_count;
    bool n_pos_key_count;

   public:
    bool _is_null_pos_key_count() {
      pos_key_count();
      return n_pos_key_count;
    };

   private:
    std::unique_ptr<std::vector<std::unique_ptr<pos_key_frame_t>>>
        m_pos_key_frames;
    bool n_pos_key_frames;

   public:
    bool _is_null_pos_key_frames() {
      pos_key_frames();
      return n_pos_key_frames;
    };

   private:
    int32_t m_rot_key_count;
    std::unique_ptr<std::vector<std::unique_ptr<rot_key_frame_t>>>
        m_rot_key_frames;
    rsm_t* m__root;
    rsm_t* m__parent;

   public:
    std::string name() const { return m_name; }
    std::string parent_name() const { return m_parent_name; }
    int32_t texture_count() const { return m_texture_count; }
    std::vector<int32_t>* texture_ids() const { return m_texture_ids.get(); }
    node_info_t* info() const { return m_info.get(); }
    int32_t node_vertex_count() const { return m_node_vertex_count; }
    std::vector<std::unique_ptr<node_vertex_t>>* node_vertices() const {
      return m_node_vertices.get();
    }
    int32_t texture_vertex_count() const { return m_texture_vertex_count; }
    std::vector<std::unique_ptr<texture_vertex_t>>* texture_vertices() const {
      return m_texture_vertices.get();
    }
    int32_t face_count() const { return m_face_count; }
    std::vector<std::unique_ptr<face_info_t>>* faces_info() const {
      return m_faces_info.get();
    }
    int32_t pos_key_count() const { return m_pos_key_count; }
    std::vector<std::unique_ptr<pos_key_frame_t>>* pos_key_frames() const {
      return m_pos_key_frames.get();
    }
    int32_t rot_key_count() const { return m_rot_key_count; }
    std::vector<std::unique_ptr<rot_key_frame_t>>* rot_key_frames() const {
      return m_rot_key_frames.get();
    }
    rsm_t* _root() const { return m__root; }
    rsm_t* _parent() const { return m__parent; }
  };

 private:
  std::string m_magic;
  uint16_t m_version;
  int32_t m_animation_count;
  shading_t m_shading_type;
  uint8_t m_alpha;
  std::string m_reserved;
  int32_t m_texture_count;
  std::unique_ptr<std::vector<std::string>> m_texture_names;
  std::string m_main_node_name;
  int32_t m_node_count;
  std::unique_ptr<std::vector<std::unique_ptr<node_t>>> m_nodes;
  int32_t m_pos_key_count;
  bool n_pos_key_count;

 public:
  bool _is_null_pos_key_count() {
    pos_key_count();
    return n_pos_key_count;
  };

 private:
  std::unique_ptr<std::vector<std::unique_ptr<pos_key_frame_t>>>
      m_pos_key_frames;
  bool n_pos_key_frames;

 public:
  bool _is_null_pos_key_frames() {
    pos_key_frames();
    return n_pos_key_frames;
  };

 private:
  int32_t m_volume_box_count;
  std::unique_ptr<std::vector<std::unique_ptr<volume_box_t>>> m_volume_boxes;
  rsm_t* m__root;
  kaitai::kstruct* m__parent;

 public:
  /**
   * File identification, must be GRSM".
   */
  std::string magic() const { return m_magic; }
  uint16_t version() const { return m_version; }
  int32_t animation_count() const { return m_animation_count; }
  shading_t shading_type() const { return m_shading_type; }
  uint8_t alpha() const { return m_alpha; }
  std::string reserved() const { return m_reserved; }
  int32_t texture_count() const { return m_texture_count; }
  std::vector<std::string>* texture_names() const {
    return m_texture_names.get();
  }
  std::string main_node_name() const { return m_main_node_name; }
  int32_t node_count() const { return m_node_count; }
  std::vector<std::unique_ptr<node_t>>* nodes() const { return m_nodes.get(); }
  int32_t pos_key_count() const { return m_pos_key_count; }
  std::vector<std::unique_ptr<pos_key_frame_t>>* pos_key_frames() const {
    return m_pos_key_frames.get();
  }
  int32_t volume_box_count() const { return m_volume_box_count; }
  std::vector<std::unique_ptr<volume_box_t>>* volume_boxes() const {
    return m_volume_boxes.get();
  }
  rsm_t* _root() const { return m__root; }
  kaitai::kstruct* _parent() const { return m__parent; }
};
}  // namespace raglib
