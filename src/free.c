/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:20:38 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:12:05 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_matrix(t_main *main, t_point ***matrix)
{
	int	y;

	y = 0;
	while (y < main->rows)
	{
		free((*matrix)[y]);
		y++;
	}
	free(*(matrix));
}

void	free_all_matrix(t_main *main)
{
	free_matrix(main, &main->matrix);
	if (main->clicked_ortho == 1)
		free_ortho_matrix(main);
}

void	free_ortho_matrix(t_main *main)
{
	free_matrix(main, &main->matrix_front);
	free_matrix(main, &main->matrix_rear);
	free_matrix(main, &main->matrix_top);
	free_matrix(main, &main->matrix_bottom);
	free_matrix(main, &main->matrix_left);
	free_matrix(main, &main->matrix_right);
}

void	free_str_arr(char **str_arr)
{
	int	i;

	i = 0;
	while (str_arr[i])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
}
