#ifndef __LLIB_H__
#define __LLIB_H__
#include <stdio.h>
#include <stdlib.h>

#ifdef USE_COLOR
#ifndef LLIB_INFO_COLOR
#define LLIB_INFO_COLOR "\x1b[1;36m"
#endif // !LLIB_INFO_COLOR

#ifndef LLIB_WARN_COLOR
#define LLIB_WARN_COLOR "\x1b[1;33m"
#endif // !LLIB_WARN_COLOR

#ifndef LLIB_ERR_COLOR
#define LLIB_ERR_COLOR  "\x1b[1;31m"
#endif // !LLIB_ERR_COLOR

#ifndef LLIB_RESET_COLOR
#define LLIB_RESET_COLOR "\x1b[0m"
#endif // !LLIB_RESET_COLOR
#else
#define LLIB_INFO_COLOR ""
#define LLIB_WARN_COLOR ""
#define LLIB_ERR_COLOR  ""

#define LLIB_RESET_COLOR ""
#endif

#ifndef LLIB_INFO_PREFIX
#define LLIB_INFO_PREFIX "[" LLIB_INFO_COLOR "INFO" LLIB_RESET_COLOR "] "
#endif // !LLIB_INFO_PREFIX

#ifndef LLIB_WARN_PREFIX
#define LLIB_WARN_PREFIX "[" LLIB_WARN_COLOR "WARN" LLIB_RESET_COLOR "] "
#endif // !LLIB_WARN_PREFIX

#ifndef LLIB_ERR_PREFIX
#define LLIB_ERR_PREFIX "[ " LLIB_ERR_COLOR "ERR" LLIB_RESET_COLOR "] "
#endif // !LLIB_ERR_PREFIX


#ifndef LLIB_INFO_CHANNEL
#define LLIB_INFO_CHANNEL stdout
#endif // !LLIB_INFO_CHANNEL

#ifndef LLIB_WARN_CHANNEL
#define LLIB_WARN_CHANNEL stderr
#endif // !LLIB_WARN_CHANNEL

#ifndef LLIB_ERR_CHANNEL
#define LLIB_ERR_CHANNEL stderr
#endif // !LLIB_ERR_CHANNEL

void default_log(const char *file, int line, const char *prefix, FILE *channel, const char *fmt, ...);

#define info(...) (default_log(__FILE__, __LINE__, LLIB_INFO_PREFIX, LLIB_INFO_CHANNEL, __VA_ARGS__))
#define warn(...) (default_log(__FILE__, __LINE__, LLIB_WARN_PREFIX, LLIB_WARN_CHANNEL, __VA_ARGS__))
#define err(...)  (default_log(__FILE__, __LINE__, LLIB_ERR_PREFIX , LLIB_ERR_CHANNEL , __VA_ARGS__))

#define log_assert(expr, message)            \
      if (!(expr)) {                         \
        err("Assertion failed in %s:%i:\t%s", __FILE__, __LINE__, #expr); \
        err("Msg: `%s`", message);           \
        abort();                             \
      }                                      \

#endif // !__LLIB_H__
