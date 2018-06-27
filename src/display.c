/*
** EPITECH PROJECT, 2017
** display
** File description:
** display function
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sokoban.h"

void help(void)
{
	write(1, "USAGE\n\t./my_sokoban map\n\t./my_sokoban -h\n", 41);
	write(1, "DESCRIPTION\n\tmap\tfile representing the ", 40);
	write(1, "warehouse map, containing `#' for walls,", 40);
	write(1, "'P' for the player, 'X' for boxes and `O' for ", 46);
	write(1, "storage locations.", 40);
}

void print_space(char *str)
{
	for(int i = 1; i < ((COLS / 2) - (my_strlen(str) / 2)); i++)
		printw(" ");
}

void print_map(t_maps load)
{
	for (int i = 0; i < load.size; i++)
		printw("%s", load.map[i]);
}
