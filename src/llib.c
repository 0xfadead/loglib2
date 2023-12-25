#include "llib.h"
#include <stdarg.h>
#include <stdio.h>

void default_log(const char *file, int line, const char *prefix, FILE *channel, const char *fmt, ...) {
  va_list args;

  va_start(args, fmt);

  fputs(prefix, channel);
  fprintf(channel, "%s:%i ", file, line);
  vfprintf(channel, fmt, args);
  fputs("\n", channel);

  va_end(args);

  return;
}
