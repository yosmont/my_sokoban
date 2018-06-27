/*
** EPITECH PROJECT, 2017
** move
** File description:
** move the player
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sokoban.h"

t_maps mv_up(t_maps load, t_pos player_pos)
{
	int new_y = player_pos.y - 1;
	int new_x = player_pos.x;

	if (load.map[new_y][new_x] == ' ' || load.map[new_y][new_x] == 'O') {
		load.map[player_pos.y][player_pos.x] = ' ';
		load.map[new_y][new_x] = 'P';
	} else if (load.map[new_y][new_x] == 'X' &&
		   (load.map[new_y - 1][new_x] == ' ' ||
		    load.map[new_y - 1][new_x] == 'O')) {
		load.map[player_pos.y][player_pos.x] = ' ';
		load.map[new_y][new_x] = 'P';
		load.map[new_y - 1][new_x] = 'X';
	}
	return(load);
}

t_maps mv_down(t_maps load, t_pos player_pos)
{
	int new_y = player_pos.y + 1;
	int new_x = player_pos.x;

	if (load.map[new_y][new_x] == ' ' || load.map[new_y][new_x] == 'O') {
		load.map[player_pos.y][player_pos.x] = ' ';
		load.map[new_y][new_x] = 'P';
	} else if (load.map[new_y][new_x] == 'X' &&
		   (load.map[new_y + 1][new_x] == ' ' ||
		    load.map[new_y + 1][new_x] == 'O')) {
		load.map[player_pos.y][player_pos.x] = ' ';
		load.map[new_y][new_x] = 'P';
		load.map[new_y + 1][new_x] = 'X';
	}
	return(load);
}

t_maps mv_left(t_maps load, t_pos player_pos)
{
	int new_y = player_pos.y;
	int new_x = player_pos.x - 1;

	if (load.map[new_y][new_x] == ' ' || load.map[new_y][new_x] == 'O') {
		load.map[player_pos.y][player_pos.x] = ' ';
		load.map[new_y][new_x] = 'P';
	} else if (load.map[new_y][new_x] == 'X' &&
		   (load.map[new_y][new_x - 1] == ' ' ||
		    load.map[new_y][new_x - 1] == 'O')) {
		load.map[player_pos.y][player_pos.x] = ' ';
		load.map[new_y][new_x] = 'P';
		load.map[new_y][new_x - 1] = 'X';
	}
	return(load);
}

t_maps mv_right(t_maps load, t_pos player_pos)
{
	int new_y = player_pos.y;
	int new_x = player_pos.x + 1;

	if (load.map[new_y][new_x] == ' ' || load.map[new_y][new_x] == 'O') {
		load.map[player_pos.y][player_pos.x] = ' ';
		load.map[new_y][new_x] = 'P';
	} else if (load.map[new_y][new_x] == 'X' &&
		   (load.map[new_y][new_x + 1] == ' ' ||
		    load.map[new_y][new_x + 1] == 'O')) {
		load.map[player_pos.y][player_pos.x] = ' ';
		load.map[new_y][new_x] = 'P';
		load.map[new_y][new_x + 1] = 'X';
	}
	return(load);
}

t_maps mv(int *check, t_pos player_pos, t_maps load, t_maps ref)
{
	switch(getch()) {
	case ' ':
		load.map = tabs_copy(ref.map, ref.size);
		break;
	case 'A':
		load = mv_up(load, player_pos);
		break;
	case 'D':
		load = mv_left(load, player_pos);
		break;
	case 'B':
		load = mv_down(load, player_pos);
		break;
	case 'C':
		load = mv_right(load, player_pos);
		break;
	case EOF:
		ncurses_quit(1);
	default:
		break;
	}
	return(load);
}
