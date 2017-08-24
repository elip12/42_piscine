/*
* ft_split_whitespaces.c
* author: Paulina Sprawska
*
* splits a string of words into a array of strings, with whitespaces as delimiters
*/

#include <stdlib.h>

int		words(char *str, int *size)
{
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != '\t') && (str[i] != '\n') && (str[i] != ' ')
			&& (str[i] != '\v'))
			w++;
		while ((str[i] != '\t') && (str[i] != '\n') && (str[i] != ' ')
			&& (str[i] != '\v') && (str[i] != '\0'))
		{
			i++;
			size[w - 1] = size[w - 1] + 1;
		}
		while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == ' ')
			|| (str[i] == '\v'))
			i++;
	}
	return (w);
}

char	**fill(int w, char *str, char **array, int *size)
{
	int		jump;
	int		i;
	int		c;

	i = 0;
	c = 0;
	jump = 0;
	while (i < w)
	{
		array[i] = (char*)malloc(sizeof(**array) * (size[i] + 1));
		while ((str[c] == ' ') || (str[c] == '\v') || (str[c] == '\t')
			|| (str[c] == '\n'))
			c++;
		while ((str[c] != ' ') && (str[c] != '\v') &&
			(str[c] != '\t') && (str[c] != '\0') && (str[c] != '\n'))
		{
			array[i][jump] = str[c];
			c++;
			jump++;
		}
		array[i][jump] = '\0';
		i++;
		jump = 0;
	}
	return (array);
}

char	**ft_split_whitespaces(char *str)
{
	int		w;
	int		size[20000];
	char	**array;

	w = 0;
	while (w < 10)
	{
		size[w] = 0;
		w++;
	}
	w = words(str, size);
	array = (char**)malloc(sizeof(*array) * (w + 1));
	fill(w, str, array, size);
	array[w] = 0;
	return (array);
}
