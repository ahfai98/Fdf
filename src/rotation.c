/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:23:31 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 15:26:09 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	radian(double angle)
{
	return (angle * PI / 180);
}

void	rotate_about_z_axis(t_main *main, t_point **matrix, double angle)
{
	int		x;
	int		y;
	double	x_new;
	double	y_new;

	y = -1;
	while (++y < main->rows)
	{
		x = -1;
		while (++x < main->columns_per_row)
		{
			x_new = matrix[y][x].x * cos(radian(angle))
				- matrix[y][x].y * sin(radian(angle));
			y_new = matrix[y][x].x * sin(radian(angle))
				+ matrix[y][x].y * cos(radian(angle));
			matrix[y][x].x = x_new;
			matrix[y][x].y = y_new;
		}
	}
}

void	rotate_about_y_axis(t_main *main, t_point **matrix, double angle)
{
	int		x;
	int		y;
	double	x_new;
	double	z_new;

	y = -1;
	while (++y < main->rows)
	{
		x = -1;
		while (++x < main->columns_per_row)
		{
			x_new = matrix[y][x].x * cos(radian(angle))
				- matrix[y][x].z * sin(radian(angle));
			z_new = matrix[y][x].z * cos(radian(angle))
				- matrix[y][x].x * sin(radian(angle));
			matrix[y][x].x = x_new;
			matrix[y][x].z = z_new;
		}
	}
}

void	rotate_about_x_axis(t_main *main, t_point **matrix, double angle)
{
	int		x;
	int		y;
	double	y_new;
	double	z_new;

	y = -1;
	while (++y < main->rows)
	{
		x = -1;
		while (++x < main->columns_per_row)
		{
			y_new = matrix[y][x].y * cos(radian(angle))
				- matrix[y][x].z * sin(radian(angle));
			z_new = matrix[y][x].y * sin(radian(angle))
				+ matrix[y][x].z * cos(radian(angle));
			matrix[y][x].y = y_new;
			matrix[y][x].z = z_new;
		}
	}
}

/*
Rotation about y axis
xnew = xcos + zsin
znew = -xsin + zcos

Rotation aboyt x axis
ynew = ycos - zsin
znew = ysin + zcos

Rotation about z axis
xnew =xcos - ysin
ynew =xsin + ycos
*/