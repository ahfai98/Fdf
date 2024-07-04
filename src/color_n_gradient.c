/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_n_gradient.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:35 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:27:11 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	extract(int color, char ch)
{
	if (ch == 'r')
		return ((color >> 16) & 0xFF);
	if (ch == 'g')
		return ((color >> 8) & 0xFF);
	if (ch == 'b')
		return (color & 0xFF);
	return (0);
}

void	init_default_colors(t_main *main, t_point **matrix)
{
	int	y;
	int	x;

	y = -1;
	while (++y < main->rows)
	{
		x = -1;
		while (++x < main->columns_per_row)
		{
			if (matrix[y][x].z != 0)
			{
				matrix[y][x].color = RED;
				if (y > 0 && (int)matrix[y - 1][x].z == 0)
					matrix[y - 1][x].color = PURPLE;
				if (y < main->rows - 1 && (int)matrix[y + 1][x].z == 0)
					matrix[y + 1][x].color = PURPLE;
				if (x > 0 && (int)matrix[y][x - 1].z == 0)
					matrix[y][x - 1].color = PURPLE;
				if (x < main->columns_per_row - 1
					&& (int)matrix[y][x + 1].z == 0)
					matrix[y][x + 1].color = PURPLE;
			}
		}
	}
}

void	remove_colors(t_main *main, t_point **matrix)
{
	int	x;
	int	y;

	y = 0;
	while (y < main->rows)
	{
		x = 0;
		while (x < main->columns_per_row)
		{
			matrix[y][x].color = WHITE;
			x++;
		}
		y++;
	}
}

void	init_colors(t_main *main, t_point **matrix)
{
	if (main->flags.init_colors)
		init_default_colors(main, matrix);
	else
		remove_colors(main, matrix);
}

int	gradient(int startcolor, int endcolor, int len, int position)
{
	double	increment[3];
	int		new[3];

	increment[0] = (double)(extract(endcolor, 'r') - extract(startcolor, 'r'))
		/ (double)len;
	increment[1] = (double)(extract(endcolor, 'g') - extract(startcolor, 'g'))
		/ (double)len;
	increment[2] = (double)(extract(endcolor, 'b') - extract(startcolor, 'b'))
		/ (double)len;
	new[0] = extract(startcolor, 'r') + round(position * increment[0]);
	new[1] = extract(startcolor, 'g') + round(position * increment[1]);
	new[2] = extract(startcolor, 'b') + round(position * increment[2]);
	return ((new[0] << 16) + (new[1] << 8) + new[2]);
}
