meta:
  id: str
  title: Ragnarok Effect Resource
  application: Ragnarok Online clients
  ks-version: 0.9
  endian: le

seq:
  - id: magic
    size: 4
    contents: ["STRM"]
    doc: File identification, must be "STRM"
  - id: version
    type: u4
    valid:
        expr: _ == 0x94

  - id: fps
    type: u4
  - id: max_key
    type: u4
  - id: layer_count
    type: u4
    valid:
        expr: _ <= 128
  - id: unknown
    size: 16
  - id: layers
    type: layer
    repeat: expr
    repeat-expr: layer_count

types:
  layer:
    seq:
      - id: texture_count
        type: s4
        valid:
          expr: _ <= 128
      - id: texture_names
        size: 128
        repeat: expr
        repeat-expr: texture_count
      - id: key_frame_count
        type: s4
        valid:
          expr: _ <= 2048
      - id: key_frames
        type: frame
        repeat: expr
        repeat-expr: key_frame_count

  frame:
    seq:
      - id: frame
        type: s4
      - id: type
        type: u4
      - id: position
        type: f4
        repeat: expr
        repeat-expr: 2
      - id: uv
        type: f4
        repeat: expr
        repeat-expr: 8
      - id: xy
        type: f4
        repeat: expr
        repeat-expr: 8
      - id: anim_frame
        type: f4
      - id: anim_type
        type: u4
      - id: delay
        type: f4
      - id: angle
        type: f4
      - id: color
        type: f4
        repeat: expr
        repeat-expr: 4
      - id: src_alpha
        type: u4
      - id: dest_alpha
        type: u4
      - id: mt_preset
        type: u4
