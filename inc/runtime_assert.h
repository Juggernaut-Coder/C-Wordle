#ifndef RT_ASSERT_H
#define RT_ASSERT_H

#include <stdlib.h>
#include <stdio.h>

#ifndef __STRING
#define __STRING(x) #x
#endif

#define rt_assert(expr, ...)                                                                                                \
  ((void) sizeof ((expr) ? 1 : 0), __extension__ ({                                                                         \
    if (!(expr)) {                                                                                                          \
        printf("At function %s in file %s:%d, assert failed: (%s). ", __func__, __FILE__, __LINE__, (#expr));               \
        printf("Error: ");                                                                                                  \
        printf(__VA_ARGS__);                                                                                                \
        printf("\n");                                                                                                       \
        exit(EXIT_FAILURE);                                                                                                 \
    }                                                                                                                       \
    })) 
#endif
