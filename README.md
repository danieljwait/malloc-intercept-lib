# Malloc Intercept Library
Library to intercept all malloc calls, outputting the amount of bytes used so far to stderr

## Build

```
$ make
```
Produces the `malloc.so` shared object.

## Usage

To intercept calls to `seq 1 5`, write
```
$ LD_PRELOAD=./malloc.so seq 1 5
```
