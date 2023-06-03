# shared

## requirements

- gcrypt-devel
- gsl-devel
- openblas-devel

## notes

- cli console was integrated originally, but we can separate this and assume control with a socket based cli
  - this is so to keep the state of the program running headlessly, server-client wise
