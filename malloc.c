#define _GNU_SOURCE // RTLD_NEXT is not in POSIX
#include <dlfcn.h>
#include <stdio.h>

static size_t total = 0;

// libc malloc
static void *(*real_malloc)(size_t size);

// override malloc
void *malloc(size_t size)
{
  // Get runtime address of `malloc` func symbol and save it once
  if (!real_malloc)
    real_malloc = dlsym(RTLD_NEXT, "malloc");

  // Do the malloc
  void *res = real_malloc(size);

  // If successful, output updated number of bytes
  if (res != NULL)
  {
    total += size;
    fprintf(stderr, "Total bytes loaded so far: %lu\n", total);
  }

  return res;
}