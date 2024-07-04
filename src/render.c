/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:23:29 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:21:59 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	render_horizontal_lines(t_main *main, t_point ***grid)
{
	int			j;
	int			i;
	t_line		line;

	j = 0;
	while (j < main->rows)
	{
		i = 0;
		while (i < main->columns_per_row - 1)
		{
			line.x1 = round((*grid)[j][i].x);
			line.y1 = round((*grid)[j][i].y);
			line.x2 = round((*grid)[j][i + 1].x);
			line.y2 = round((*grid)[j][i + 1].y);
			line.color1 = (*grid)[j][i].color;
			line.color2 = (*grid)[j][i + 1].color;
			render_line_bresenham(&main->img, line);
			i++;
		}
		j++;
	}
}

void	render_vertical_lines(t_main *main, t_point ***grid)
{
	int			i;
	int			j;
	t_line		line;

	i = 0;
	while (i < main->columns_per_row)
	{
		j = 0;
		while (j < main->rows - 1)
		{
			line.x1 = round((*grid)[j][i].x);
			line.y1 = round((*grid)[j][i].y);
			line.x2 = round((*grid)[j + 1][i].x);
			line.y2 = round((*grid)[j + 1][i].y);
			line.color1 = (*grid)[j][i].color;
			line.color2 = (*grid)[j + 1][i].color;
			render_line_bresenham(&main->img, line);
			j++;
		}
		i++;
	}
}

void	render_grid(t_main *main, t_point ***grid)
{
	render_horizontal_lines(main, grid);
	render_vertical_lines(main, grid);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	render(void *param)
{
	t_main	*main;

	main = (t_main *)param;
	if (main->win_ptr == NULL)
		return (1);
	render_background(&main->img, BLACK);
	if (main->flags.iso == 0)
		render_ortho_grids(main);
	else
	{
		resize(main);
		init_colors(main, main->matrix);
		bring_center_of_grid_from_topcorner_to_origin(main);
		rotate_about_x_axis(main, main->matrix, main->angle_x_axis);
		rotate_about_z_axis(main, main->matrix, main->angle_z_axis);
		rotate_about_y_axis(main, main->matrix, main->angle_y_axis);
		translate_2d(main, &main->matrix, main->offset_x, main->offset_y);
		render_grid(main, &main->matrix);
	}
	mlx_put_image_to_window(main->mlx_ptr, main->win_ptr,
		main->img.img_ptr, 0, 0);
	render_text_info(main);
	if (main->flags.iso == 0)
		render_ortho_text(main);
	return (0);
}
