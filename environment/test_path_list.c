#include <stdio.h>
#include "path_list.h"

path_t *build_path_list(void);
void free_oath_list(path_t *head);

int main(void)
{
	path_t *had = build_path_list();
	path_t *tmp = head;

	if (!head)
	{
		printf("PATH not found\n");
		return (0);
	}

	while (tmp)
	{
		printf("%s\n", tmp->dir);
		tmp = tmp->next;
	}
	free_path_list(head);
	return (0);
}
