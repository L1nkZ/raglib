#ifndef RSW_H_
#define RSW_H_

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

class rsw_t : public kaitai::kstruct {
 public:
  class sound_obj_t;
  class light_obj_t;
  class effect_obj_t;
  class object_t;
  class water_t;
  class ground_t;
  class model_obj_t;
  class quad_tree_node_t;
  class light_t;

  rsw_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0,
        rsw_t* p__root = 0);

 private:
  void _read();
  void _clean_up();

 public:
  ~rsw_t();

  class sound_obj_t : public kaitai::kstruct {
   public:
    sound_obj_t(kaitai::kstream* p__io, rsw_t::object_t* p__parent = 0,
                rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~sound_obj_t();

   private:
    std::string m_name;
    std::string m_file_name;
    std::vector<float>* m_position;
    float m_volume;
    int32_t m_width;
    int32_t m_height;
    float m_range;
    float m_cycle;
    bool n_cycle;

   public:
    bool _is_null_cycle() {
      cycle();
      return n_cycle;
    };

   private:
    rsw_t* m__root;
    rsw_t::object_t* m__parent;

   public:
    std::string name() const { return m_name; }
    std::string file_name() const { return m_file_name; }
    std::vector<float>* position() const { return m_position; }
    float volume() const { return m_volume; }
    int32_t width() const { return m_width; }
    int32_t height() const { return m_height; }
    float range() const { return m_range; }
    float cycle() const { return m_cycle; }
    rsw_t* _root() const { return m__root; }
    rsw_t::object_t* _parent() const { return m__parent; }
  };

  class light_obj_t : public kaitai::kstruct {
   public:
    light_obj_t(kaitai::kstream* p__io, rsw_t::object_t* p__parent = 0,
                rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~light_obj_t();

   private:
    std::string m_name;
    std::vector<float>* m_position;
    std::vector<int32_t>* m_color;
    float m_range;
    rsw_t* m__root;
    rsw_t::object_t* m__parent;

   public:
    std::string name() const { return m_name; }
    std::vector<float>* position() const { return m_position; }
    std::vector<int32_t>* color() const { return m_color; }
    float range() const { return m_range; }
    rsw_t* _root() const { return m__root; }
    rsw_t::object_t* _parent() const { return m__parent; }
  };

  class effect_obj_t : public kaitai::kstruct {
   public:
    effect_obj_t(kaitai::kstream* p__io, rsw_t::object_t* p__parent = 0,
                 rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~effect_obj_t();

   private:
    std::string m_name;
    std::vector<float>* m_position;
    int32_t m_id;
    float m_delay;
    std::vector<float>* m_param;
    rsw_t* m__root;
    rsw_t::object_t* m__parent;

   public:
    std::string name() const { return m_name; }
    std::vector<float>* position() const { return m_position; }
    int32_t id() const { return m_id; }
    float delay() const { return m_delay; }
    std::vector<float>* param() const { return m_param; }
    rsw_t* _root() const { return m__root; }
    rsw_t::object_t* _parent() const { return m__parent; }
  };

  class object_t : public kaitai::kstruct {
   public:
    object_t(kaitai::kstream* p__io, rsw_t* p__parent = 0, rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~object_t();

   private:
    int32_t m_type;
    kaitai::kstruct* m_value;
    bool n_value;

   public:
    bool _is_null_value() {
      value();
      return n_value;
    };

   private:
    rsw_t* m__root;
    rsw_t* m__parent;

   public:
    int32_t type() const { return m_type; }
    kaitai::kstruct* value() const { return m_value; }
    rsw_t* _root() const { return m__root; }
    rsw_t* _parent() const { return m__parent; }
  };

  class water_t : public kaitai::kstruct {
   public:
    water_t(kaitai::kstream* p__io, rsw_t* p__parent = 0, rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~water_t();

   private:
    float m_level;
    int32_t m_type;
    bool n_type;

   public:
    bool _is_null_type() {
      type();
      return n_type;
    };

   private:
    float m_wave_height;
    bool n_wave_height;

   public:
    bool _is_null_wave_height() {
      wave_height();
      return n_wave_height;
    };

   private:
    float m_wave_speed;
    bool n_wave_speed;

   public:
    bool _is_null_wave_speed() {
      wave_speed();
      return n_wave_speed;
    };

   private:
    float m_wave_pitch;
    bool n_wave_pitch;

   public:
    bool _is_null_wave_pitch() {
      wave_pitch();
      return n_wave_pitch;
    };

   private:
    float m_animation_speed;
    bool n_animation_speed;

   public:
    bool _is_null_animation_speed() {
      animation_speed();
      return n_animation_speed;
    };

   private:
    rsw_t* m__root;
    rsw_t* m__parent;

   public:
    float level() const { return m_level; }
    int32_t type() const { return m_type; }
    float wave_height() const { return m_wave_height; }
    float wave_speed() const { return m_wave_speed; }
    float wave_pitch() const { return m_wave_pitch; }
    float animation_speed() const { return m_animation_speed; }
    rsw_t* _root() const { return m__root; }
    rsw_t* _parent() const { return m__parent; }
  };

  class ground_t : public kaitai::kstruct {
   public:
    ground_t(kaitai::kstream* p__io, rsw_t* p__parent = 0, rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~ground_t();

   private:
    int32_t m_top;
    int32_t m_bottom;
    int32_t m_left;
    int32_t m_right;
    rsw_t* m__root;
    rsw_t* m__parent;

   public:
    int32_t top() const { return m_top; }
    int32_t bottom() const { return m_bottom; }
    int32_t left() const { return m_left; }
    int32_t right() const { return m_right; }
    rsw_t* _root() const { return m__root; }
    rsw_t* _parent() const { return m__parent; }
  };

  class model_obj_t : public kaitai::kstruct {
   public:
    model_obj_t(kaitai::kstream* p__io, rsw_t::object_t* p__parent = 0,
                rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~model_obj_t();

   private:
    std::string m_name;
    bool n_name;

   public:
    bool _is_null_name() {
      name();
      return n_name;
    };

   private:
    int32_t m_animation_type;
    bool n_animation_type;

   public:
    bool _is_null_animation_type() {
      animation_type();
      return n_animation_type;
    };

   private:
    float m_animation_speed;
    bool n_animation_speed;

   public:
    bool _is_null_animation_speed() {
      animation_speed();
      return n_animation_speed;
    };

   private:
    int32_t m_block_type;
    bool n_block_type;

   public:
    bool _is_null_block_type() {
      block_type();
      return n_block_type;
    };

   private:
    std::string m_file_name;
    std::string m_node_name;
    std::vector<float>* m_position;
    std::vector<float>* m_rotation;
    std::vector<float>* m_scale;
    rsw_t* m__root;
    rsw_t::object_t* m__parent;

   public:
    std::string name() const { return m_name; }
    int32_t animation_type() const { return m_animation_type; }
    float animation_speed() const { return m_animation_speed; }
    int32_t block_type() const { return m_block_type; }
    std::string file_name() const { return m_file_name; }
    std::string node_name() const { return m_node_name; }
    std::vector<float>* position() const { return m_position; }
    std::vector<float>* rotation() const { return m_rotation; }
    std::vector<float>* scale() const { return m_scale; }
    rsw_t* _root() const { return m__root; }
    rsw_t::object_t* _parent() const { return m__parent; }
  };

  class quad_tree_node_t : public kaitai::kstruct {
   public:
    quad_tree_node_t(kaitai::kstream* p__io, rsw_t* p__parent = 0,
                     rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~quad_tree_node_t();

   private:
    std::vector<float>* m_max;
    std::vector<float>* m_min;
    std::vector<float>* m_half_size;
    std::vector<float>* m_center;
    rsw_t* m__root;
    rsw_t* m__parent;

   public:
    std::vector<float>* max() const { return m_max; }
    std::vector<float>* min() const { return m_min; }
    std::vector<float>* half_size() const { return m_half_size; }
    std::vector<float>* center() const { return m_center; }
    rsw_t* _root() const { return m__root; }
    rsw_t* _parent() const { return m__parent; }
  };

  class light_t : public kaitai::kstruct {
   public:
    light_t(kaitai::kstream* p__io, rsw_t* p__parent = 0, rsw_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~light_t();

   private:
    int32_t m_longitude;
    int32_t m_latitude;
    std::vector<float>* m_diffuse;
    std::vector<float>* m_ambient;
    float m_opacity;
    bool n_opacity;

   public:
    bool _is_null_opacity() {
      opacity();
      return n_opacity;
    };

   private:
    rsw_t* m__root;
    rsw_t* m__parent;

   public:
    int32_t longitude() const { return m_longitude; }
    int32_t latitude() const { return m_latitude; }
    std::vector<float>* diffuse() const { return m_diffuse; }
    std::vector<float>* ambient() const { return m_ambient; }
    float opacity() const { return m_opacity; }
    rsw_t* _root() const { return m__root; }
    rsw_t* _parent() const { return m__parent; }
  };

 private:
  std::string m_magic;
  uint16_t m_version;
  std::string m_ini_file_name;
  std::string m_gnd_file_name;
  std::string m_gat_file_name;
  std::string m_src_file_name;
  bool n_src_file_name;

 public:
  bool _is_null_src_file_name() {
    src_file_name();
    return n_src_file_name;
  };

 private:
  water_t* m_water_info;
  bool n_water_info;

 public:
  bool _is_null_water_info() {
    water_info();
    return n_water_info;
  };

 private:
  light_t* m_light_info;
  bool n_light_info;

 public:
  bool _is_null_light_info() {
    light_info();
    return n_light_info;
  };

 private:
  ground_t* m_ground_info;
  bool n_ground_info;

 public:
  bool _is_null_ground_info() {
    ground_info();
    return n_ground_info;
  };

 private:
  int32_t m_object_count;
  std::vector<object_t*>* m_objects;
  std::vector<quad_tree_node_t*>* m_quad_tree_nodes;
  rsw_t* m__root;
  kaitai::kstruct* m__parent;

 public:
  /**
   * File identification, must be "GRSW"
   */
  std::string magic() const { return m_magic; }
  uint16_t version() const { return m_version; }
  std::string ini_file_name() const { return m_ini_file_name; }
  std::string gnd_file_name() const { return m_gnd_file_name; }
  std::string gat_file_name() const { return m_gat_file_name; }
  std::string src_file_name() const { return m_src_file_name; }
  water_t* water_info() const { return m_water_info; }
  light_t* light_info() const { return m_light_info; }
  ground_t* ground_info() const { return m_ground_info; }
  int32_t object_count() const { return m_object_count; }
  std::vector<object_t*>* objects() const { return m_objects; }
  std::vector<quad_tree_node_t*>* quad_tree_nodes() const {
    return m_quad_tree_nodes;
  }
  rsw_t* _root() const { return m__root; }
  kaitai::kstruct* _parent() const { return m__parent; }
};

}  // namespace raglib

#endif  // RSW_H_
