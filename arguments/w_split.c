#include <stdlib.h>

/* vérifier si un caractère est un séparateur */
int is_delim(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

/* compter le nombre de mots*/
int count_words(char *str)
{
	int i = 0, count = 0;
	while (str[i])
	{
		if (!is_delim(str[i]) &&
			(i == 0 || is_delim(str[i - 1])))
			count++;
	}
	return (count);
}

/*copier un mot*/
char *copy_word(char *str, int start, int len)
{
	char *word;
	int i = 0;

	word = malloc(len + 1);
	if (!word)
		return (NULL);

	while (i < len)
	{
		word[i] = str[start + 1];
		i++;
	}
	word[i] = '\0';

	return (word);
}

/* split sans utiliser strtok*/
char **split_line(char *str)
{
	char **array;
	int i = 0, j = 0, start;
	int words = count_words(str);

	array = malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);

	while (str[i])
	{
		if (!is_delim(str[i]))
		{
			start = i;
			while (str[i] && !is_delim(str[i]))
				i++;
			array[j++] = copy_word(str, start, i - start);
		}
		else
			i++;
	}
	array[j] = NULL;
	return (array);
}
