meta:
  id: rsw
  title: Ragnarok World Resource
  application: Ragnarok Online clients
  ks-version: 0.9
  endian: le
  
seq:
  - id: magic
    size: 4
    contents: ["GRSW"]
    doc: File identification, must be "GRSW"
  - id: version
    type: u2be

  - id: ini_file_name
    size: 40
  - id: gnd_file_name
    size: 40
  - id: gat_file_name
    size: 40
  - id: src_file_name
    size: 40
    if: version >= 0x104

  # Water
  - id: water_info
    type: water
    if: version >= 0x103

  # Light
  - id: light_info
    type: light
    if: version >= 0x105

  # Ground
  - id: ground_info
    type: ground
    if: version >= 0x106

  # World objects
  - id: object_count
    type: s4
    valid:
      expr: _ <= 65536
  - id: objects
    type: object
    repeat: expr
    repeat-expr: object_count

  - id: quad_tree_nodes
    type: quad_tree_node
    repeat: eos

types:
  water:
    seq:
      - id: level
        type: f4
      - id: type
        type: s4
        if: _root.version >= 0x108
      - id: wave_height
        type: f4
        if: _root.version >= 0x108
      - id: wave_speed
        type: f4
        if: _root.version >= 0x108
      - id: wave_pitch
        type: f4
        if: _root.version >= 0x108
      - id: animation_speed
        type: f4
        if: _root.version >= 0x108

  light:
    seq:
      - id: longitude
        type: s4
      - id: latitude
        type: s4
      - id: diffuse
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: ambient
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: opacity
        type: f4
        if: _root.version >= 0x107

  ground:
    seq:
      - id: top
        type: s4
      - id: bottom
        type: s4
      - id: left
        type: s4
      - id: right
        type: s4

  model_obj:
    seq:
      - id: name
        size: 40
        if: _root.version >= 0x103
      - id: animation_type
        type: s4
        if: _root.version >= 0x103
      - id: animation_speed
        type: f4
        if: _root.version >= 0x103
      - id: block_type
        type: s4
        if: _root.version >= 0x103
      - id: file_name
        size: 80
      - id: node_name
        size: 80
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: rotation
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: scale
        type: f4
        repeat: expr
        repeat-expr: 3

  light_obj:
    seq:
      - id: name
        size: 80
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: color
        type: s4
        repeat: expr
        repeat-expr: 3
      - id: range
        type: f4

  sound_obj:
    seq:
      - id: name
        size: 80
      - id: file_name
        size: 80
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: volume
        type: f4
      - id: width
        type: s4
      - id: height
        type: s4
      - id: range
        type: f4
      - id: cycle
        type: f4
        if: _root.version >= 0x200

  effect_obj:
    seq:
      - id: name
        size: 80
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: id
        type: s4
      - id: delay
        type: f4
      - id: param
        type: f4
        repeat: expr
        repeat-expr: 4

  object: 
    seq:
      - id: type
        type: s4
        valid:
          expr: _ >= 1 and _ <= 4
      - id: value
        type:
          switch-on: type
          cases:
            1: model_obj
            2: light_obj
            3: sound_obj
            4: effect_obj
   
  quad_tree_node:
    seq:
      - id: max
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: min
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: half_size
        type: f4
        repeat: expr
        repeat-expr: 3
      - id: center
        type: f4
        repeat: expr
        repeat-expr: 3
