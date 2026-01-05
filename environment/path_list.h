#ifndef PATH_LIST_H
#define PATH_LSIT_H

/**
 * struct path_s - linked list of PATH directories
 * @dir: directory string
 * @next: pointer to the next node
 */
typedef struct path_s
{
	char *dir;
	struct path_s *next;
} path_t;

#endif