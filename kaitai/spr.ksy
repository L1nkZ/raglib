meta:
  id: spr
  title: Ragnarok Sprite Resource
  application: Ragnarok Online clients
  ks-version: 0.9
  endian: le

seq:
  - id: magic
    size: 2
    contents: ["SP"]
    doc: File identification, must be "SP"
  - id: version
    type: u2

  - id: indexed_image_count
    type: u2

  - id: rgba_image_count
    type: u2
    if: version > 0x101

  - id: indexed_images
    type: indexed_image
    repeat: expr
    repeat-expr: indexed_image_count
    if: version < 0x201

  - id: indexed_rle_images
    type: indexed_rle_image
    repeat: expr
    repeat-expr: indexed_image_count
    if: version >= 0x201

  - id: rgba_images
    type: rgba_image
    repeat: expr
    repeat-expr: rgba_image_count

  - id: palette
    size: 1024
    if: version > 0x100 and indexed_image_count > 0

types:
  indexed_image:
    seq:
      - id: width
        type: u2
      - id: height
        type: u2
        valid:
          expr: width * height <= 1073741824
      - id: data
        size: width * height

  indexed_rle_image:
    seq:
      - id: width
        type: u2
      - id: height
        type: u2
      - id: data_size
        type: u2
      - id: rle_runs
        type: rle_runs
        size: data_size

  rgba_image:
    seq:
      - id: width
        type: u2
      - id: height
        type: u2
        valid:
          expr: width * height * 4 <= 1073741824
      - id: data
        size: width * height * 4

  rle_runs:
    seq:
      - id: runs
        type: rle_run
        repeat: eos

  rle_run:
    seq:
      - id: value
        type: u1
      - id: count
        type: u1
        if: value == 0
