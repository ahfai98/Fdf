/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:23:35 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:06:06 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	bring_center_of_grid_from_topcorner_to_origin(t_main *main)
{
	int	grid_width;
	int	grid_height;

	translate_2d(main, &main->matrix, -main->matrix[0][0].x,
		-main->matrix[0][0].y);
	grid_width = main->columns_per_row + (main->columns_per_row - 1)
		* (main->gap - 1);
	grid_height = main->rows + (main->rows - 1) * (main->gap - 1);
	translate_2d(main, &main->matrix, -(grid_width / 2), -(grid_height / 2));
}

void	reset_grid(t_main *main)
{
	main->angle_z_axis = 0;
	main->angle_x_axis = 20;
	main->angle_y_axis = 20;
	main->z_scale = 0.2;
	main->flags.iso = 1;
	main->gap = 20;
	resize(main);
	bring_center_of_grid_from_topcorner_to_origin(main);
	main->offset_x = WINDOW_WIDTH / 2;
	main->offset_y = WINDOW_HEIGHT / 2;
}

t_point	**duplicate_coordinates(t_main *main, t_point **matrix)
{
	int		y;
	t_point	**ori;

	ori = ft_calloc(main->rows, sizeof(t_point *));
	if (ori == NULL)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	y = 0;
	while (y < main->rows)
	{
		ori[y] = ft_calloc(main->columns_per_row, sizeof(t_point));
		ft_memcpy(ori[y], matrix[y], main->columns_per_row * sizeof(t_point));
		y++;
	}
	return (ori);
}

void	create_original_matrix_copy(t_main *main)
{
	main->matrix_ori = duplicate_coordinates(main, main->matrix);
	translate_2d(main, &main->matrix_ori,
		-main->columns_per_row / 2, -main->rows / 2);
}
