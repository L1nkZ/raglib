meta:
  id: act
  title: Ragnarok Action Resource
  application: Ragnarok Online clients
  ks-version: 0.9
  endian: le
  
seq:
  - id: magic
    size: 2
    contents: ["AC"]
    doc: File identification, must be "AC"
  - id: version
    type: u2

  - id: action_count
    type: u2
    valid:
      expr: _ <= 256
  - id: unknown
    size: 10
  - id: actions
    type: action
    repeat: expr
    repeat-expr: action_count
  - id: sound_file_count
    type: s4
    valid:
      expr: _ <= 256
    if: version >= 0x201
  - id: sound_files
    size: 40
    repeat: expr
    repeat-expr: sound_file_count
    if: version >= 0x201
  - id: animation_speeds
    type: f4
    repeat: eos
    if: version >= 0x202

types:
  action:
    seq:
      - id: frame_count
        type: u4
        valid:
          expr: _ <= 256
      - id: frames
        type: frame
        repeat: expr
        repeat-expr: frame_count

  frame:
    seq:
      - id: unknown
        size: 32
      - id: layer_count
        type: u4
        valid:
          expr: _ <= 256
      - id: layers
        type: layer
        repeat: expr
        repeat-expr: layer_count
      - id: sound_id
        type: s4
        if: _root.version >= 0x200
      - id: anchor_count
        type: s4
        valid:
          expr: _ <= 256
        if: _root.version >= 0x203
      - id: anchors
        type: anchor
        repeat: expr
        repeat-expr: anchor_count
        if: _root.version >= 0x203

  layer:
    seq:
      - id: position
        type: s4
        repeat: expr
        repeat-expr: 2
      - id: index
        type: s4
      - id: is_mirror
        type: s4
      - id: color
        type: u1
        repeat: expr
        repeat-expr: 4
        if: _root.version >= 0x200
      - id: scale_x
        type: f4
        if: _root.version >= 0x200
      - id: scale_y
        type: f4
        if: _root.version >= 0x204
      - id: angle
        type: s4
        if: _root.version >= 0x200
      - id: spr_type
        type: s4
        if: _root.version >= 0x200
      - id: width
        type: s4
        if: _root.version >= 0x205
      - id: height
        type: s4
        if: _root.version >= 0x205

  anchor:
    seq:
      - id: unknown1
        size: 4
      - id: offset
        type: s4
        repeat: expr
        repeat-expr: 2
      - id: unknown2
        size: 4
