#ifndef __PT_DIRENT_H
#define __PT_DIRENT_H

#include <errno.h>
#include <sys/stat.h>
#include <limits.h>
#ifdef _WIN32
#include <windows.h>
#include <stdint.h>
#ifndef FILENAME_MAX
#define FILENAME_MAX 260
#endif
#ifndef DT_DIR
#define DT_DIR 0x00
#define DT_REG 0x10
#endif
#include "pt_unicode.h"

typedef struct dirent
{
    UNICHAR d_name[FILENAME_MAX];
    uint16_t d_namlen;
    uint32_t d_type;
#ifdef _WIN32
    uint32_t d_size;
    char lastModDate[6 + 1];
#endif
} dirent;

typedef struct DIR
{
    dirent fd;
    HANDLE fHandle;
    WIN32_FIND_DATAW fData;
} DIR;

DIR *opendir(UNICHAR *name);
struct dirent *readdir(DIR *dirp);
int32_t closedir(DIR *dirp);
#else
#include <dirent.h>
#endif

#endif
