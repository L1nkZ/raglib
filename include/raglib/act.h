#ifndef ACT_H_
#define ACT_H_

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

class act_t : public kaitai::kstruct {
 public:
  class action_t;
  class frame_t;
  class layer_t;
  class anchor_t;

  act_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0,
        act_t* p__root = 0);

 private:
  void _read();
  void _clean_up();

 public:
  ~act_t();

  class action_t : public kaitai::kstruct {
   public:
    action_t(kaitai::kstream* p__io, act_t* p__parent = 0, act_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~action_t();

   private:
    uint32_t m_frame_count;
    std::vector<frame_t*>* m_frames;
    act_t* m__root;
    act_t* m__parent;

   public:
    uint32_t frame_count() const { return m_frame_count; }
    std::vector<frame_t*>* frames() const { return m_frames; }
    act_t* _root() const { return m__root; }
    act_t* _parent() const { return m__parent; }
  };

  class frame_t : public kaitai::kstruct {
   public:
    frame_t(kaitai::kstream* p__io, act_t::action_t* p__parent = 0,
            act_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~frame_t();

   private:
    std::string m_unknown;
    uint32_t m_layer_count;
    std::vector<layer_t*>* m_layers;
    int32_t m_sound_id;
    bool n_sound_id;

   public:
    bool _is_null_sound_id() {
      sound_id();
      return n_sound_id;
    };

   private:
    int32_t m_anchor_count;
    bool n_anchor_count;

   public:
    bool _is_null_anchor_count() {
      anchor_count();
      return n_anchor_count;
    };

   private:
    std::vector<anchor_t*>* m_anchors;
    bool n_anchors;

   public:
    bool _is_null_anchors() {
      anchors();
      return n_anchors;
    };

   private:
    act_t* m__root;
    act_t::action_t* m__parent;

   public:
    std::string unknown() const { return m_unknown; }
    uint32_t layer_count() const { return m_layer_count; }
    std::vector<layer_t*>* layers() const { return m_layers; }
    int32_t sound_id() const { return m_sound_id; }
    int32_t anchor_count() const { return m_anchor_count; }
    std::vector<anchor_t*>* anchors() const { return m_anchors; }
    act_t* _root() const { return m__root; }
    act_t::action_t* _parent() const { return m__parent; }
  };

  class layer_t : public kaitai::kstruct {
   public:
    layer_t(kaitai::kstream* p__io, act_t::frame_t* p__parent = 0,
            act_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~layer_t();

   private:
    std::vector<int32_t>* m_position;
    int32_t m_index;
    int32_t m_is_mirror;
    std::vector<uint8_t>* m_color;
    bool n_color;

   public:
    bool _is_null_color() {
      color();
      return n_color;
    };

   private:
    float m_scale_x;
    bool n_scale_x;

   public:
    bool _is_null_scale_x() {
      scale_x();
      return n_scale_x;
    };

   private:
    float m_scale_y;
    bool n_scale_y;

   public:
    bool _is_null_scale_y() {
      scale_y();
      return n_scale_y;
    };

   private:
    int32_t m_angle;
    bool n_angle;

   public:
    bool _is_null_angle() {
      angle();
      return n_angle;
    };

   private:
    int32_t m_spr_type;
    bool n_spr_type;

   public:
    bool _is_null_spr_type() {
      spr_type();
      return n_spr_type;
    };

   private:
    int32_t m_width;
    bool n_width;

   public:
    bool _is_null_width() {
      width();
      return n_width;
    };

   private:
    int32_t m_height;
    bool n_height;

   public:
    bool _is_null_height() {
      height();
      return n_height;
    };

   private:
    act_t* m__root;
    act_t::frame_t* m__parent;

   public:
    std::vector<int32_t>* position() const { return m_position; }
    int32_t index() const { return m_index; }
    int32_t is_mirror() const { return m_is_mirror; }
    std::vector<uint8_t>* color() const { return m_color; }
    float scale_x() const { return m_scale_x; }
    float scale_y() const { return m_scale_y; }
    int32_t angle() const { return m_angle; }
    int32_t spr_type() const { return m_spr_type; }
    int32_t width() const { return m_width; }
    int32_t height() const { return m_height; }
    act_t* _root() const { return m__root; }
    act_t::frame_t* _parent() const { return m__parent; }
  };

  class anchor_t : public kaitai::kstruct {
   public:
    anchor_t(kaitai::kstream* p__io, act_t::frame_t* p__parent = 0,
             act_t* p__root = 0);

   private:
    void _read();
    void _clean_up();

   public:
    ~anchor_t();

   private:
    std::string m_unknown1;
    std::vector<int32_t>* m_offset;
    std::string m_unknown2;
    act_t* m__root;
    act_t::frame_t* m__parent;

   public:
    std::string unknown1() const { return m_unknown1; }
    std::vector<int32_t>* offset() const { return m_offset; }
    std::string unknown2() const { return m_unknown2; }
    act_t* _root() const { return m__root; }
    act_t::frame_t* _parent() const { return m__parent; }
  };

 private:
  std::string m_magic;
  uint16_t m_version;
  uint16_t m_action_count;
  std::string m_unknown;
  std::vector<action_t*>* m_actions;
  int32_t m_sound_file_count;
  bool n_sound_file_count;

 public:
  bool _is_null_sound_file_count() {
    sound_file_count();
    return n_sound_file_count;
  };

 private:
  std::vector<std::string>* m_sound_files;
  bool n_sound_files;

 public:
  bool _is_null_sound_files() {
    sound_files();
    return n_sound_files;
  };

 private:
  std::vector<float>* m_animation_speeds;
  bool n_animation_speeds;

 public:
  bool _is_null_animation_speeds() {
    animation_speeds();
    return n_animation_speeds;
  };

 private:
  act_t* m__root;
  kaitai::kstruct* m__parent;

 public:
  /**
   * File identification, must be "AC"
   */
  std::string magic() const { return m_magic; }
  uint16_t version() const { return m_version; }
  uint16_t action_count() const { return m_action_count; }
  std::string unknown() const { return m_unknown; }
  std::vector<action_t*>* actions() const { return m_actions; }
  int32_t sound_file_count() const { return m_sound_file_count; }
  std::vector<std::string>* sound_files() const { return m_sound_files; }
  std::vector<float>* animation_speeds() const { return m_animation_speeds; }
  act_t* _root() const { return m__root; }
  kaitai::kstruct* _parent() const { return m__parent; }
};

}  // namespace raglib

#endif  // ACT_H_
