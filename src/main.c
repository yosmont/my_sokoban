/*
** EPITECH PROJECT, 2017
** main
** File description:
** main function
*/

#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sokoban.h"

int main(int ac, char **av)
{
	int res = 0;

	if (ac >= 2 && av[1][0] == '-' && av[1][1] == 'h') {
		help();
	} else
		res = init_sokoban(ac, av);
	return(res);
}
