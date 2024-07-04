/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_event.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:43 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:12:05 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	handle_translation(int keycode, t_main *main)
{
	if (keycode == KEY_RIGHT)
		main->offset_x += 10;
	else if (keycode == KEY_LEFT)
		main->offset_x -= 10;
	else if (keycode == KEY_UP)
		main->offset_y -= 10;
	else if (keycode == KEY_DOWN)
		main->offset_y += 10;
	else
		return ;
}

void	reset_angle(double *angle)
{
	if (round(*angle) == 360)
		*angle = 0;
	else if (round(*angle) == -360)
		*angle = 0;
}

void	handle_rotate(int keycode, t_main *main)
{
	if (keycode == KEY_D)
		main->angle_z_axis += 10;
	else if (keycode == KEY_A)
		main->angle_z_axis += -10;
	else if (keycode == KEY_W)
		main->angle_x_axis += 10;
	else if (keycode == KEY_S)
		main->angle_x_axis += -10;
	else if (keycode == KEY_Q)
		main->angle_y_axis += 10;
	else if (keycode == KEY_E)
		main->angle_y_axis += -10;
	reset_angle(&main->angle_x_axis);
	reset_angle(&main->angle_y_axis);
	reset_angle(&main->angle_z_axis);
	return ;
}

void	if_other_key_pressed(int keycode, t_main *main)
{
	if (keycode == KEY_Z)
		main->z_scale += 0.03;
	else if (keycode == KEY_X)
		main->z_scale -= 0.03;
	else if (keycode == KEY_DOT)
	{
		if (main->flags.init_colors)
			main->flags.init_colors = 0;
		else
			main->flags.init_colors = 1;
	}
	else if (keycode == KEY_O)
	{
		if (main->flags.iso)
			main->flags.iso = 0;
		else
			main->flags.iso = 1;
		main->clicked_ortho = 1;
		init_ortho_grids(main);
		transform_ortho_grids(main);
	}
	if (main->z_scale > 5 || main->z_scale < -5)
		main->z_scale = 0.2;
}

int	handle_key_event(int keycode, void *param)
{
	t_main	*main;

	main = (t_main *)param;
	if (keycode == KEY_ESC)
		close_window(main);
	else if (keycode == KEY_R)
	{
		reset_grid(main);
		if (main->flags.iso == 0)
		{
			free_ortho_matrix(main);
			main->flags.iso = 1;
		}
	}
	else if (keycode == KEY_PLUS)
		main->gap++;
	else if (keycode == KEY_MINUS && main->gap - 1 > 0)
		main->gap--;
	handle_translation(keycode, main);
	handle_rotate(keycode, main);
	if_other_key_pressed(keycode, main);
	return (0);
}
