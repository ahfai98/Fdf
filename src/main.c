/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:45 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:12:05 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	close_window(void *param)
{
	t_main	*main;

	main = (t_main *)param;
	mlx_destroy_image(main->mlx_ptr, main->img.img_ptr);
	mlx_destroy_window(main->mlx_ptr, main->win_ptr);
	free_all_matrix(main);
	exit(0);
}

void	init_main(t_main *main)
{
	main->rows = 0;
	main->columns_per_row = 0;
	main->gap = 20;
	main->z_scale = 0.6;
	main->offset_x = 0;
	main->offset_y = 0;
	main->angle_x_axis = 20;
	main->angle_y_axis = 20;
	main->angle_z_axis = 0;
	main->flags.iso = 1;
	main->flags.init_colors = 1;
	main->clicked_ortho = 0;
}

int	mlx(t_main *main)
{
	main->mlx_ptr = mlx_init();
	if (main->mlx_ptr == NULL)
		return (1);
	main->win_ptr = mlx_new_window(main->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"FDF");
	if (main->win_ptr == NULL)
	{
		mlx_destroy_window(main->mlx_ptr, main->win_ptr);
		return (1);
	}
	main->img.img_ptr = mlx_new_image(main->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	main->img.addr = mlx_get_data_addr(main->img.img_ptr,
			&main->img.bpp, &main->img.line_len, &main->img.endian);
	mlx_loop_hook(main->mlx_ptr, &render, main);
	mlx_hook(main->win_ptr, ON_KEYDOWN, 1L << 0, &handle_key_event, main);
	mlx_hook(main->win_ptr, ON_DESTROY, 0, &close_window, main);
	mlx_loop(main->mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_main	main;

	if (ac != 2)
	{
		ft_putstr_fd("Error: Number of Arguments should be 2.\n", 2);
		ft_putstr_fd("./fdf <filename.fdf>\n", 2);
		exit(1);
	}
	init_main(&main);
	main.rows = get_rows(av[1]);
	parsing(av[1], &main);
	create_original_matrix_copy(&main);
	reset_grid(&main);
	mlx(&main);
	return (0);
}
