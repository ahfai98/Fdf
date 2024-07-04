/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:39:09 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:26:23 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "macros.h"
# include "../minilibx_macos/mlx.h"
# include "structs.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi_base(char *str, char *base);
int		get_rows(char *input);
void	parsing(char *input, t_main *main);

void	img_pix_put(t_img *img, int x, int y, int color);

int		close_window(void *params);
int		handle_key_event(int keycode, void *param);

void	render_background(t_img *img, int color);
int		render(void *param);
void	render_grid(t_main *main, t_point ***grid);

void	render_line_bresenham(t_img *img, t_line line);
void	render_line_low(t_img *img, t_line line);

void	render_line_high(t_img *img, t_line line);

void	reset_grid(t_main *main);

void	multiply_matrix_to_grid(t_main *main, t_point ***matrix1,
			double matrix[3][3]);

void	translate_2d(t_main *main, t_point ***matrix, double tx, double ty);

void	resize(t_main *main);
double	radian(double angle);
void	rotate_about_z_axis(t_main *main, t_point **matrix, double angle);
void	rotate_about_x_axis(t_main *main, t_point **matrix, double angle);
void	rotate_about_y_axis(t_main *main, t_point **matrix, double angle);

void	bring_center_of_grid_from_topcorner_to_origin(t_main *main);
void	init_main(t_main *main);
void	reset_grid(t_main *main);
void	create_original_matrix_copy(t_main *main);
t_point	**duplicate_coordinates(t_main *main, t_point **matrix);

int		gradient(int startcolor, int endcolor, int len, int pos);
void	init_default_colors(t_main *main, t_point **matrix);
void	init_colors(t_main *main, t_point **matrix);
void	remove_colors(t_main *main, t_point **matrix);
int		extract(int color, char ch);
int		combine_rgb(int red, int green, int blue);

void	init_ortho_grids(t_main *main);
void	transform_ortho_grids(t_main *main);
void	render_ortho_grids(t_main *main);

void	free_matrix(t_main *main, t_point ***matrix);
void	free_all_matrix(t_main *main);
void	free_ortho_matrix(t_main *main);
void	free_str_arr(char **split);
void	render_text_info(t_main *main);
void	render_text_info_sub(t_main *main, int y);
void	render_ortho_text(t_main *main);

#endif