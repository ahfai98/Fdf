/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:23:38 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 14:30:53 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	translate_2d(t_main *main, t_point ***matrix, double tx, double ty)
{
	int	y;
	int	x;

	y = 0;
	while (y < main->rows)
	{
		x = 0;
		while (x < main->columns_per_row)
		{
			(*matrix)[y][x].x += tx;
			(*matrix)[y][x].y += ty;
			x++;
		}
		y++;
	}
}

void	resize(t_main *main)
{
	int	y;
	int	x;

	y = 0;
	while (y < main->rows)
	{
		x = 0;
		while (x < main->columns_per_row)
		{
			main->matrix[y][x].x = main->matrix_ori[y][x].x * main->gap;
			main->matrix[y][x].y = main->matrix_ori[y][x].y * main->gap;
			main->matrix[y][x].z = main->matrix_ori[y][x].z * (main->gap
					* main->z_scale);
			x++;
		}
		y++;
	}
}
