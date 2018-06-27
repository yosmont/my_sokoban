/*
** EPITECH PROJECT, 2017
** init
** File description:
** initialise t_pos and t_map
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sokoban.h"

t_pos get_p_pos(t_pos player_pos, t_maps map)
{
	int i = 0;
	int j = 0;
	
	for (i; i < map.size && map.map[i][j] != 'P'; i++) {
		for (j = 0; map.map[i][j] != '\0' && map.map[i][j] != 'P';j++);
		if (map.map[i][j] == 'P')
			i--;
	}
	player_pos.x = j;
	player_pos.y = i;
	return(player_pos);
}

int nbrline(char *str)
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	int size = 0;

	stream = fopen(str, "r");
	if (stream == NULL)
		exit(84);
	while(getline(&line, &len, stream) != -1)
		size++;
	free(line);
	fclose(stream);
	return(size);
}

t_maps create_map(char *str, t_maps load)
{
	FILE *stream;
	char *line;
	size_t len = 0;
	ssize_t read;
	int i = 0;

	load.size = nbrline(str);
	load.map = malloc(sizeof(char *) * load.size);
	stream = fopen(str, "r");
	if (stream == NULL)
		exit(84);
	while ((read = getline(&line, &len, stream)) != -1) {
		load.map[i] = my_strdup(line);
		i++;
	}
	free(line);
	fclose(stream);
	return(load);
}

t_maps max_len(t_maps load)
{
	int tmp = 0;

	load.len = 0;
	for (int i = 0; i < load.size; i++) {
		tmp = my_strlen(load.map[i]);
		if (tmp > load.len)
			load.len = tmp;
	}
	return(load);
}

int init_sokoban(int ac, char **av)
{
	t_pos player_pos = {0, 0};
	t_maps ref;
	t_maps load;
	char *str = "map/map.txt";

	if (ac == 1)
		ncurses_quit(84);
	str = my_strdup(av[1]);
	load = create_map(str, load);
	ref.map = tabs_copy(load.map, load.size);
	ref.size = load.size;
	player_pos = get_p_pos(player_pos, load);
	check_map(load);
	initscr();
	raw();
	game_loop(load, ref, player_pos);
	endwin();
	return(0);
}
