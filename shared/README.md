# shared

## requirements

- gcrypt-devel
- gsl-devel
- openblas-devel

## notes

- cli console was integrated originally, but we can separate this and assume control with a socket based cli
  - this is so to keep the state of the program running headlessly, server-client wise
- we are trying to mirror the src as close as possible to trace any issues along the way with development
- for conf files, consider using json or YAML

### networking

- consider using a procedural method for making packets
- two sections, info and payload
- info is fixed, payload varies in length
- default buffer size is 4096, but can expand as necessary
- once completed, prepare packet to be sent out
- on receiving, creates two structs, one for permanent information (src by addr), the other by payload cursor
- function only goes forward, not backwards
- can be resetted to home position as needed
- functions packet_cur_type, packet_cur_size, packet_val_csifd packet_val_str packet_val_bin/struct, packet_next
