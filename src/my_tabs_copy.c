/*
** EPITECH PROJECT, 2017
** my tabs copy
** File description:
** copy a tabs
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(char *str);

char **tabs_copy(char **map, int size)
{
	char **mapref = malloc(sizeof(char *) * size);

	for (int i = 0; i < size; i++)
		mapref[i] = my_strdup(map[i]);
	return(mapref);
}
