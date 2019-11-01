#ifndef SHIM_SYS_TIMERFD_H
#define SHIM_SYS_TIMERFD_H

#ifdef __cplusplus
extern "C" {
#endif

#include <fcntl.h>
#include <time.h>

#define TFD_NONBLOCK O_NONBLOCK
#define TFD_CLOEXEC O_CLOEXEC

#define TFD_TIMER_ABSTIME 1

struct itimerspec;

int timerfd_create(int /*clockid*/, int /*flags*/);
int timerfd_settime(int /*fd*/, int /*flags*/,
    const struct itimerspec * /*new*/, struct itimerspec * /*old*/);
#if 0
int timerfd_gettime(int, struct itimerspec *);
#endif


#ifndef SHIM_SYS_SHIM_HELPERS
#define SHIM_SYS_SHIM_HELPERS
#include <unistd.h> /* IWYU pragma: keep */

extern int epoll_shim_close(int);
extern ssize_t epoll_shim_read(int, void *, size_t);
extern ssize_t epoll_shim_write(int, void const*, size_t);
#define close epoll_shim_close
#define read epoll_shim_read
#define write epoll_shim_write
#endif


#ifdef __cplusplus
}
#endif

#endif
