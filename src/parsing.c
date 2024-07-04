/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:23:22 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 14:52:11 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	count_words(char *str, char c)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (*str != c && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (*str == c)
			flag = 1;
		str++;
	}
	return (count);
}

int	get_rows(char *input)
{
	int	rows;
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		perror("Unable to open file");
		return (1);
	}
	rows = 0;
	while (1)
	{
		input = get_next_line(fd);
		if (input == NULL)
			break ;
		rows++;
		free(input);
	}
	close(fd);
	return (rows);
}

void	store_info_in_matrix_line_y(t_main *main, char **split, int y)
{
	int	i;
	int	x;

	x = 0;
	while (x < main->columns_per_row)
	{
		main->matrix[y][x].x = x;
		main->matrix[y][x].y = y;
		main->matrix[y][x].z = ft_atoi(split[x]);
		if (ft_strchr((const char *)split[x], ',') != NULL)
		{
			i = 0;
			while (split[x][i] != 'x')
				i++;
			main->matrix[y][x].color = ft_atoi_base((&split[x][++i]),
					"0123456789ABCDEF");
		}
		else
			main->matrix[y][x].color = WHITE;
		x++;
	}
}

void	parse_lines(t_main *main, int fd)
{
	int		y;
	char	*line;
	char	**split;

	y = 0;
	while (y < main->rows)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		main->columns_per_row = count_words(line, ' ');
		main->matrix[y] = malloc(main->columns_per_row
				* sizeof(t_point));
		if (main->matrix[y] == NULL)
		{
			perror("Failed to allocate memory");
			exit(EXIT_FAILURE);
		}
		store_info_in_matrix_line_y(main, split, y);
		free(line);
		free_str_arr(split);
		y++;
	}
}

void	parsing(char *input, t_main *main)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
	{
		perror("Unable to open the file");
		exit(1);
	}
	main->matrix = malloc(main->rows * sizeof(t_point *));
	parse_lines(main, fd);
}
