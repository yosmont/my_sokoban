/*
** EPITECH PROJECT, 2017
** sokoban
** File description:
** my sokoban header
*/

typedef struct position {
	int x;
	int y;
} t_pos;

typedef struct tabs_and_size {
	char **map;
	int size;
	int len;
} t_maps;

int my_strlen(char const *str);
char *my_strdup(char *src);
char **tabs_copy(char **map, int size);
void ncurses_quit(int nb);
int check_victory(t_maps load, t_maps ref);
t_maps check_O(t_maps load, t_maps ref);
void check_map(t_maps load);
void check_loose(t_maps load);
t_pos get_p_pos(t_pos player_pos, t_maps map);
int nbrline(char *str);
t_maps create_map(char *str, t_maps load);
t_maps max_len(t_maps load);
int init_sokoban(int ac, char **av);
t_maps mv_up(t_maps load, t_pos player_pos);
t_maps mv_down(t_maps load, t_pos player_pos);
t_maps mv_left(t_maps load, t_pos player_pos);
t_maps mv_right(t_maps load, t_pos player_pos);
t_maps mv(int *check, t_pos player_pos, t_maps load, t_maps ref);
void help(void);
void print_space(char *str);
void print_map(t_maps load);
void game_loop(t_maps load, t_maps ref, t_pos player_pos);
