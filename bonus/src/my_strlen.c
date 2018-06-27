/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** rework06
*/

int my_strlen(char const *str)
{
	int len;

	len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return(len);
}
