#ifndef _PRINT_H_
#define _PRINT_H_

#include <stdarg.h>

#define PRINT_LEVEL_0 "info"
#define PRINT_LEVEL_1 "warn"
#define PRINT_LEVEL_2 "error"

extern char * const temp;

int print(const char *format, ...);

#endif //_PRINT_H_
