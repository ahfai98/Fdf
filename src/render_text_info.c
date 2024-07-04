/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_text_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:23:27 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 15:55:23 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	render_text_info_sub(t_main *main, int y)
{
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		ft_strjoin("Rotation about x-axis : ", ft_itoa(main->angle_x_axis)));
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		ft_strjoin("Rotation about y-axis : ", ft_itoa(main->angle_y_axis)));
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		ft_strjoin("Rotation about z-axis : ", ft_itoa(main->angle_z_axis)));
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		ft_strjoin("Offset X : ", ft_itoa(main->offset_x)));
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		ft_strjoin("Offset Y : ", ft_itoa(main->offset_x)));
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		ft_strjoin("Scale : ", ft_itoa(main->gap)));
}

void	render_text_info(t_main *main)
{
	int	y;

	y = 30;
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Close window: ESC");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Reset: R");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Rotate abt x-axis: W / S");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Rotate abt z-axis: A / D");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Rotate abt y-axis: Q / E");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Translate: Arrow keys");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Zoom: + / -");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"z scale: Z / X");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Colors On/Off : .");
	mlx_string_put(main->mlx_ptr, main->win_ptr, 15, y += 30, WHITE,
		"Isometric/Orthographic View: O");
	render_text_info_sub(main, y);
}
