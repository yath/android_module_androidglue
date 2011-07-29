#ifndef _ANDROIDGLUE_H_
#define _ANDROIDGLUE_H_

# define setfsuid(x) (x)
# define setfsgid(x) (x)

# define fdatasync(fd) fsync(fd)

# define lutimes(fd, tv) utimes(fd, tv)
#endif
