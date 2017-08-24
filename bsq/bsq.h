/*
* bsq.h
* author: Eli Pandolfo
*
* Header file for bsq.c. Prototypes the 3 functions that are included in separate files
* (from bsq.c), and includes all other necessary header files. Protected from double inclusion.
*/

#ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>

char		**ft_split_whitespaces(char *str);
int			ft_atoi(char *str);
void    	create_malloc(char *file, char **buf, int *ret, int fd);

#endif
