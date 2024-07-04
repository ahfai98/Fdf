/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:39:15 by jyap              #+#    #+#             */
/*   Updated: 2024/05/17 17:12:05 by jyap             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_point;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_flags
{
	int		iso;
	int		init_colors;
}			t_flags;

typedef struct s_main
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_point	**matrix;
	t_point	**matrix_ori;
	int		rows;
	int		columns_per_row;
	double	gap;
	double	z_scale;
	int		offset_x;
	int		offset_y;
	double	angle_x_axis;
	double	angle_y_axis;
	double	angle_z_axis;
	t_flags	flags;
	t_point	**matrix_top;
	t_point	**matrix_bottom;
	t_point	**matrix_front;
	t_point	**matrix_rear;
	t_point	**matrix_left;
	t_point	**matrix_right;
	int		clicked_ortho;
}			t_main;

typedef struct s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		color1;
	int		color2;
}			t_line;

typedef struct s_line_bresenham_var
{
	int		dx;
	int		dy;
	int		d;
	int		x;
	int		y;
	int		xi;
	int		yi;
}			t_line_bresenham_var;

#endif