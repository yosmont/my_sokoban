/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** Task 01/08
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strdup(char *src)
{
	char *dest;
	int i = 0;

        dest = malloc(sizeof(char) * (my_strlen(src) + 1));
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
