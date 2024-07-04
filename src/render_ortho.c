/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ortho.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:23:33 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:12:47 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	init_ortho_grids(t_main *main)
{
	main->gap = 0;
	if (main->z_scale > 1.1)
		main->z_scale = 1.1;
	else if (main->z_scale < -1.1)
		main->z_scale = -1.1;
	if (((main->columns_per_row + (main->columns_per_row - 1)
				* (main->gap - 1)) < 400))
	{
		while ((main->columns_per_row + (main->columns_per_row - 1)
				* (main->gap - 1)) < 400)
			main->gap++;
	}
	else
		main->gap = 1;
	resize(main);
	bring_center_of_grid_from_topcorner_to_origin(main);
	main->matrix_top = duplicate_coordinates(main, main->matrix);
	main->matrix_bottom = duplicate_coordinates(main, main->matrix);
	main->matrix_front = duplicate_coordinates(main, main->matrix);
	main->matrix_rear = duplicate_coordinates(main, main->matrix);
	main->matrix_left = duplicate_coordinates(main, main->matrix);
	main->matrix_right = duplicate_coordinates(main, main->matrix);
}

void	transform_ortho_grids(t_main *main)
{
	rotate_about_x_axis(main, main->matrix_bottom, 180);
	rotate_about_x_axis(main, main->matrix_front, 90);
	rotate_about_x_axis(main, main->matrix_rear, 90);
	rotate_about_y_axis(main, main->matrix_rear, 180);
	rotate_about_y_axis(main, main->matrix_left, -90);
	rotate_about_x_axis(main, main->matrix_left, 90);
	rotate_about_y_axis(main, main->matrix_right, 90);
	rotate_about_x_axis(main, main->matrix_left, 90);
	translate_2d(main, &main->matrix_top, WINDOW_WIDTH * 1 / 4, WINDOW_HEIGHT
		* 1 / 8);
	translate_2d(main, &main->matrix_bottom, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT
		* 1 / 8);
	translate_2d(main, &main->matrix_front, WINDOW_WIDTH * 1 / 4,
		WINDOW_HEIGHT * 4 / 8);
	translate_2d(main, &main->matrix_rear, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT
		* 4 / 8);
	translate_2d(main, &main->matrix_left, WINDOW_WIDTH * 1 / 4, WINDOW_HEIGHT
		* 7 / 8);
	translate_2d(main, &main->matrix_right, WINDOW_WIDTH * 3 / 4, WINDOW_HEIGHT
		* 7 / 8);
}

void	render_ortho_text(t_main *main)
{
	mlx_string_put(main->mlx_ptr, main->win_ptr, 800,
		WINDOW_HEIGHT * 1 / 8, WHITE, "Top View");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 1700,
		WINDOW_HEIGHT * 1 / 8, WHITE, "Bottom View");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 800,
		WINDOW_HEIGHT * 4 / 8, WHITE, "Front View");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 1700,
		WINDOW_HEIGHT * 4 / 8, WHITE, "Rear View");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 800,
		WINDOW_HEIGHT * 7 / 8, WHITE, "Left View");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 1700,
		WINDOW_HEIGHT * 7 / 8, WHITE, "Right View");
}

void	render_ortho_grids(t_main *main)
{
	render_grid(main, &main->matrix_top);
	render_grid(main, &main->matrix_bottom);
	render_grid(main, &main->matrix_front);
	render_grid(main, &main->matrix_rear);
	render_grid(main, &main->matrix_left);
	render_grid(main, &main->matrix_right);
}
