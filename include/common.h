#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

#include <assert.h>

#if defined(_MSC_VER)
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#else
#define LIKELY(x) __builtin_expect(!!(x), 1)
#define UNLIKELY(x) __builtin_expect(!!(x), 0)
#endif

#define ASSERT(e)                                                              \
  if (UNLIKELY(!(e)))                                                          \
    do {                                                                       \
      printf("%s:%u: failed '%s'%s\n", __FILE__, __LINE__, #e, "");            \
      std::abort();                                                            \
  } while (false)
