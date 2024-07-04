/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:32 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 14:30:32 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;
	dst = img->addr + y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)dst = color;
}

void	render_line_low(t_img *img, t_line line)
{
	t_line_bresenham_var	var;

	var.dx = line.x2 - line.x1;
	var.dy = line.y2 - line.y1;
	var.yi = 1;
	if (var.dy < 0)
		var.yi = -1;
	var.d = (2 * abs(var.dy)) - var.dx;
	var.x = line.x1;
	var.y = line.y1;
	while (var.x <= line.x2)
	{
		img_pix_put(img, round(var.x), round(var.y), gradient(line.color1,
				line.color2, abs(var.dx), var.x - line.x1));
		if (var.d > 0)
		{
			var.y += var.yi;
			var.d += 2 * (abs(var.dy) - var.dx);
		}
		else
			var.d += 2 * abs(var.dy);
		var.x++;
	}
}

void	render_line_high(t_img *img, t_line line)
{
	t_line_bresenham_var	var;

	var.dy = line.y2 - line.y1;
	var.dx = line.x2 - line.x1;
	var.xi = 1;
	if (var.dx < 0)
		var.xi = -1;
	var.d = (2 * var.dy) - abs(var.dx);
	var.x = line.x1;
	var.y = line.y1;
	while (var.y <= line.y2)
	{
		img_pix_put(img, round(var.x), round(var.y), gradient(line.color1,
				line.color2, abs(var.dy), var.y - line.y1));
		if (var.d > 0)
		{
			var.x += var.xi;
			var.d += (2 * (abs(var.dx) - var.dy));
		}
		else
			var.d += (2 * abs(var.dx));
		var.y++;
	}
}

void	swap_coordinates(t_line *line)
{
	int	tmp;

	tmp = line->x1;
	line->x1 = line->x2;
	line->x2 = tmp;
	tmp = line->y1;
	line->y1 = line->y2;
	line->y2 = tmp;
	tmp = line->color1;
	line->color1 = line->color2;
	line->color2 = tmp;
}

void	render_line_bresenham(t_img *img, t_line line)
{
	if (abs(line.x2 - line.x1) > abs(line.y2 - line.y1))
	{
		if (line.x1 > line.x2)
		{
			swap_coordinates(&line);
			render_line_low(img, line);
		}
		else
			render_line_low(img, line);
	}
	else
	{
		if (line.y1 > line.y2)
		{
			swap_coordinates(&line);
			render_line_high(img, line);
		}
		else
			render_line_high(img, line);
	}
}
