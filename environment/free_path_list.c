#include <stdlib.h>
#include "path_list.h"

/**
 * free_path_list(char **path_list)
 * @path_list: array to free
 */
void free_path_list(char **path_list)
{
	int i = 0;
	if (!path_list)
		return;

	while (path_list[i])
	{
		free(path_list[i]);
		i++;
	}
	free(path_list);
}
