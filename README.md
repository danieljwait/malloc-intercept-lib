# Malloc Intercept Library
Library to intercept all malloc calls, outputting the amount of bytes used so far to stderr

## Build

```bash
make
```
Produces the `malloc.so` shared object.

## Usage

```bash
LD_PRELOAD=./malloc.so seq 1 5
```
Intercepts calls to `seq 1 5`
