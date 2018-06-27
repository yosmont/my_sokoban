/*
** EPITECH PROJECT, 2017
** quit
** File description:
** quit function
*/

#include <ncurses.h>
#include <stdlib.h>

void ncurses_quit(int nb)
{
	endwin();
	exit(nb);
}
