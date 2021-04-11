meta:
  id: gnd
  title: Ragnarok Ground Resource
  application: Ragnarok Online clients
  ks-version: 0.9
  endian: le
  
seq:
  - id: magic
    size: 4
    contents: ["GRGN"]
    doc: File identification, must be "GRGN"
  - id: version
    type: u2be
  - id: width
    type: u4
    valid:
      expr: _ <= 512
  - id: height
    type: u4
    valid:
      expr: _ <= 512
  - id: zoom
    type: f4

  # Textures
  - id: texture_count
    type: u4
    valid:
      expr: _ <= 1024
  - id: texture_name_size
    type: u4
    valid:
      expr: _ <= 1024
  - id: texture_names
    size: texture_name_size
    repeat: expr
    repeat-expr: texture_count

  # Lightmaps
  - id: lightmap_cell_count
    type: u4
    valid:
      expr: _ <= 262144
  - id: lightmap_grid_size_x
    type: u4
    valid:
      expr: _ <= 8
  - id: lightmap_grid_size_y
    type: u4
    valid:
      expr: _ <= 8
  - id: lightmap_cell_size
    type: u4
    valid:
      expr: _ <= 8
  - id: lightmap_data
    size: 4 * lightmap_cell_count * lightmap_grid_size_x * lightmap_grid_size_y * lightmap_cell_size
      
  # Tiles
  - id: tile_count
    type: u4
    valid:
      expr: _ <= 262144
  - id: tiles
    type: tile
    repeat: expr
    repeat-expr: tile_count

  # Surfaces
  - id: surfaces
    type: surface
    repeat: expr
    repeat-expr: width * height

types:
  tile:
    seq:
      - id: u
        type: f4
        repeat: expr
        repeat-expr: 4
      - id: v
        type: f4
        repeat: expr
        repeat-expr: 4
      - id: texture_id
        type: u2
      - id: light
        type: u2
      - id: color
        size: 4

  surface:
    seq:
      - id: height
        type: f4
        repeat: expr
        repeat-expr: 4
      - id: tile_up
        type: s4
      - id: tile_front
        type: s4
      - id: tile_right
        type: s4
      