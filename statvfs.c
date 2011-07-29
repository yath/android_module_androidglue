#include "sys/statvfs.h"
#include <sys/statfs.h>

int statvfs(const char *path, struct statvfs *vfs) {
    struct statfs sfs;
    int ret;
    int *fsid;
    if ((ret = statfs(path, &sfs)) != 0)
        return ret;

#define map(to,from) vfs->to = sfs.from
    map(f_bsize,   f_bsize);
    map(f_frsize,  f_frsize);
    map(f_blocks,  f_blocks);
    map(f_bfree,   f_bfree);
    map(f_bavail,  f_bavail);
    map(f_files,   f_files);
    map(f_ffree,   f_ffree);
    map(f_namemax, f_namelen);

    vfs->f_favail = 0; // FIXME
    vfs->f_flag   = 0;

    fsid = (int *)&sfs.f_fsid;
    vfs->f_fsid   = (fsid[0] << sizeof(fsid[0])) | fsid[1];

    return ret;
}
