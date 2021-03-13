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
  - id: reserved
    size: 16
  # Textures
  - id: texture_count
    type: s4
  - id: texture_names
    size: 40
    repeat: expr
    repeat-expr: texture_count
  # Nodes
  - id: main_node_name
    size: 40
  - id: node_count
    type: s4
  - id: nodes
    type: node
    repeat: expr
    repeat-expr: node_count
  # Position keys
  - id: pos_key_count
    type: s4
    if: _root.version < 0x105
  - id: pos_key_frames
    type: pos_key_frame
    repeat: expr
    repeat-expr: pos_key_count
    if: _root.version < 0x105
  # Volume boxes
  - id: volume_box_count
    type: s4
  - id: volume_boxes
    type: volume_box
    repeat: expr
    repeat-expr: volume_box_count
  
enums:
  shading:
    0: none
    1: flat
    2: smooth
    
types:
  node:
    seq:
      - id: name
        size: 40
      - id: parent_name
        size: 40
      - id: texture_count
        type: s4
      - id: texture_ids
        type: s4
        repeat: expr
        repeat-expr: texture_count
      - id: info
        type: node_info
      # Vertices
      - id: node_vertex_count
        type: s4
      - id: node_vertices
        type: node_vertex
        repeat: expr
        repeat-expr: node_vertex_count
      - id: texture_vertex_count
        type: s4
      - id: texture_vertices
        type: texture_vertex
        repeat: expr
        repeat-expr: texture_vertex_count
      # Faces
      - id: face_count
        type: s4
      - id: faces_info
        type: face_info
        repeat: expr
        repeat-expr: face_count
      # Translation keys
      - id: pos_key_count
        type: s4
        if: _root.version >= 0x105
      - id: pos_key_frames
        type: pos_key_frame
        repeat: expr
        repeat-expr: pos_key_count
        if: _root.version >= 0x105
      # Rotation keys
      - id: rot_key_count
        type: s4
      - id: rot_key_frames
        type: rot_key_frame
        repeat: expr
        repeat-expr: rot_key_count

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
      - id: rotation_angle
        type: f4
      - id: rotation_axis
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: scale
        type: f4
        repeat: expr
        repeat-expr: 3

  node_vertex:
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
      - id: node_vertex_ids
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
      - id: smooth_group
        type: s4
        if: _root.version >= 0x102

  pos_key_frame:
    seq:
      - id: frame_id
        type: s4
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3

  rot_key_frame:
    seq:
      - id: frame_id
        type: s4
      - id: quaternion
        type: f4
        repeat: expr
        repeat-expr: 4

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
        