/*
* malloc.c
* author: Paulina Sprawska
*
* dynamically allocates a buffer, to hold the data stored in a file that the
* program reads in from the command line. The function finds the size (bytes) of
* the file, then allocates that number of bytes for the buffer so as not to waste
* memory
*/

#include <stdio.h>
#include "bsq.h"

void    create_malloc(char *file, char **buf, int *ret, int fd)
{
    int     len;

    len = 0;
    *buf = (char *)malloc(4096);
    while ((*ret = read(fd, *buf, 4096)) == 4096)
        len += 4096;
    len += *ret;
    free(*buf);
    close(fd);
    if((fd = open(file, O_RDWR)) != -1)
    {
    	*buf = (char*)malloc(len + 1);
    	*ret = read(fd, *buf, len);
    	(*buf)[*ret] = '\0';
    }
}
