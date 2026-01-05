#include <stdio.h>
#include "path_list.h"

int main(void)
{
	char **path_list;
	int i = 0;

	path_list = build_path_list();

	if (!path_list)
	{
		printf("PATH not found\n");
		return (1);
	}

	while (path_list[i])
	{
		printf("%s\n", path_list[i]);
		i++;
	}
	free_path_list(path_list);
	return (0);
}
