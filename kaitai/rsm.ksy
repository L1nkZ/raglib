meta:
  id: rsm
  title: Ragnarok Model Resource
  application: Ragnarok Online clients
  ks-version: 0.9
  endian: le
  
seq:
  - id: magic
    size: 4
    contents: ["GRSM"]
    doc: File identification, must be "GRSM".
  - id: version
    type: u2be
  - id: animation_count
    type: s4
  - id: shading_type
    type: s4
    enum: shading
  - id: alpha
    type: u1
    if: _root.version >= 0x104
  - id: reserved
    size: 16
    if: _root.version < 0x200

  # Version 0x20X
  - id: frame_rate_per_second
    type: f4
    if: _root.version >= 0x202
  # Textures
  - id: texture_count
    type: s4
    if: _root.version <= 0x202
  - id: texture_names
    type: string
    repeat: expr
    repeat-expr: texture_count
    if: _root.version <= 0x202
  # Root nodes
  - id: root_node_count
    type: s4
    if: _root.version >= 0x202
  - id: root_node_names
    type: string
    repeat: expr
    repeat-expr: root_node_count
    if: _root.version >= 0x202
  - id: root_node_name
    type: string
    if: _root.version < 0x200

  # Nodes
  - id: node_count
    type: s4
  - id: nodes
    type: node
    repeat: expr
    repeat-expr: node_count

  # Scale key frames
  - id: scale_key_count
    type: s4
    if: _root.version < 0x106
  - id: scale_key_frames
    type: scale_key_frame
    repeat: expr
    repeat-expr: scale_key_count
    if: _root.version < 0x106

  # Volume boxes
  - id: volume_box_count
    type: s4
    if: not _io.eof
  - id: volume_boxes
    type: volume_box
    repeat: expr
    repeat-expr: volume_box_count
    if: not _io.eof
  
enums:
  shading:
    0: none
    1: flat
    2: smooth
    
types:
  node:
    seq:
      - id: name
        type: string
      - id: parent_name
        type: string

      # Textures
      - id: texture_count
        type: s4
      - id: texture_names
        type: string
        repeat: expr
        repeat-expr: texture_count
        if: _root.version >= 0x203
      - id: texture_ids
        type: s4
        repeat: expr
        repeat-expr: texture_count
        if: _root.version < 0x203

      # Node transformations
      - id: info
        type: node_info

      # Vertices
      - id: mesh_vertex_count
        type: s4
      - id: mesh_vertices
        type: mesh_vertex
        repeat: expr
        repeat-expr: mesh_vertex_count
      - id: texture_vertex_count
        type: s4
      - id: texture_vertices
        type: texture_vertex
        repeat: expr
        repeat-expr: texture_vertex_count

      # Faces
      - id: face_count
        type: s4
      - id: faces
        type: face_info
        repeat: expr
        repeat-expr: face_count

      # Scale key frames
      - id: scale_key_count
        type: s4
        if: _root.version >= 0x106
      - id: scale_key_frames
        type: scale_key_frame
        repeat: expr
        repeat-expr: scale_key_count
        if: _root.version >= 0x106

      # Rotation key frames
      - id: rot_key_count
        type: s4
      - id: rot_key_frames
        type: rot_key_frame
        repeat: expr
        repeat-expr: rot_key_count

      # Translation key frames
      - id: pos_key_count
        type: s4
        if: _root.version >= 0x202
      - id: pos_key_frames
        type: pos_key_frame
        repeat: expr
        repeat-expr: pos_key_count
        if: _root.version >= 0x202

      # Animated textures
      - id: animated_texture_count
        type: s4
        if: _root.version >= 0x203
      - id: animated_textures
        type: animated_texture
        repeat: expr
        repeat-expr: animated_texture_count
        if: _root.version >= 0x203

  node_info:
    seq:
      - id: offset_matrix
        type: f4
        repeat: expr
        repeat-expr: 9
      - id: offset_vector
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3
        if: _root.version < 0x202
      - id: rotation_angle
        type: f4
        if: _root.version < 0x202
      - id: rotation_axis
        type: f4
        repeat: expr
        repeat-expr: 3
        if: _root.version < 0x202
      - id: scale
        type: f4
        repeat: expr
        repeat-expr: 3
        if: _root.version < 0x202

  mesh_vertex:
    seq:
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3

  texture_vertex:
    seq:
      - id: color
        type: u4
        if: _root.version >= 0x102
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 2
        
  face_info:
    seq:
      - id: length
        type: s4
        if: _root.version >= 0x202
      - id: mesh_vertex_ids
        type: u2
        repeat: expr
        repeat-expr: 3
      - id: texture_vertex_ids
        type: u2
        repeat: expr
        repeat-expr: 3
      - id: texture_id
        type: u2
      - id: padding
        type: u2
      - id: two_sides
        type: s4
      - id: smooth_group_x
        type: s4
        if: _root.version >= 0x102
      - id: smooth_group_y
        type: s4
        if: _root.version >= 0x202 and length > 24
      - id: smooth_group_z
        type: s4
        if: _root.version >= 0x202 and length > 28

  pos_key_frame:
    seq:
      - id: frame_id
        type: s4
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: data
        type: s4

  rot_key_frame:
    seq:
      - id: frame_id
        type: s4
      - id: quaternion
        type: f4
        repeat: expr
        repeat-expr: 4

  scale_key_frame:
    seq:
      - id: frame_id
        type: s4
      - id: scale
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: data
        type: f4

  texture_key_frame:
    seq:
      - id: frame_id
        type: s4
      - id: offset
        type: f4

  volume_box:
    seq:
      - id: size
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: rotation
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: flag
        type: s4
        if: _root.version >= 0x103
        
  animated_texture:
    seq:
      - id: texture_id
        type: s4
      - id: animation_count
        type: s4
      - id: tex_animations
        type: tex_animation
        repeat: expr
        repeat-expr: animation_count

  tex_animation:
    seq:
      - id: type
        type: s4
      # Texture key frames
      - id: tex_frame_count
        type: s4
      - id: tex_key_frames
        type: texture_key_frame
        repeat: expr
        repeat-expr: tex_frame_count

  string:
    seq:
      - id: len
        type: s4
        if: _root.version > 0x200
      - id: value
        size: _root.version > 0x200 ? len : 40
