/*
** EPITECH PROJECT, 2017
** check
** File description:
** check different things
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sokoban.h"

int check_victory(t_maps load, t_maps ref)
{
	int i = 0;
	int check = 0;
	
	for (int j = 0; i < load.size; j++) {
		if (ref.map[i][j] == 'O' && load.map[i][j] == 'X')
			check = 1;
		else if ((ref.map[i][j] == 'O' && load.map[i][j] == 'P') ||
			load.map[i][j] == 'O')
			return(0);
		else if (load.map[i][j] == '\n') {
			i++;
			j = 0;
		}
	}
	return(check);
}

t_maps check_O(t_maps load, t_maps ref)
{
	for(int i = 0; i < ref.size; i++)
		for(int j = 0; ref.map[i][j] != '\0'; j++)
			if(ref.map[i][j] == 'O' && load.map[i][j] == ' ')
				load.map[i][j] = 'O';
	return(load);
}

void check_map(t_maps load)
{
	for (int i = 0; i < load.size; i++) {
		for (int j = 0; load.map[i][j] != '\0'; j++)
			if (load.map[i][j] != ' ' && load.map[i][j] != 'X' &&
			    load.map[i][j] != '#' && load.map[i][j] != 'O' &&
			    load.map[i][j] != 'P' && load.map[i][j] != '\n' &&
			    load.map[i][j] != '\0')
				exit(84);
	}
}

void check_loose(t_maps load)
{
	int check_block = 0;
	int check_stuck = 0;
	
	for (int i = 0; i < load.size; i++) {
		for (int j = 0; load.map[i][j] != '\0'; j++) {
			if (load.map[i][j] == 'X' &&
			    ((load.map[i][j + 1] == '#' &&
			      load.map[i + 1][j] == '#') ||
			     (load.map[i + 1][j] == '#' &&
			      load.map[i][j - 1] == '#') ||
			     (load.map[i][j - 1] == '#' &&
			      load.map[i - 1][j] == '#') ||
			     (load.map[i - 1][j] == '#' &&
			      load.map[i][j + 1] == '#')))
				check_stuck++;
			if (load.map[i][j] == 'X')
				check_block++;
		}
	}
	if (check_stuck == check_block)
		ncurses_quit(1);
}
