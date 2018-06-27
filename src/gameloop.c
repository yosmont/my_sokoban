/*
** EPITECH PROJECT, 2017
** game loop
** File description:
** game loop
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sokoban.h"

void game_loop(t_maps load, t_maps ref, t_pos player_pos)
{
	int check = 0;

	load = max_len(load);
	while (check != 1) {
		clear();
		if (load.size > LINES || load.len > COLS) {
			mvprintw(LINES / 2 - 1, (COLS / 2) - 12,
				 "Please, resize the window");
		} else {
			print_map(load);
		}
		check_loose(load);
		load = mv(&check, player_pos, load, ref);
		player_pos = get_p_pos(player_pos, load);
		load = check_O(load, ref);
		if (check != 1)
			check = check_victory(load, ref);
	}
}
