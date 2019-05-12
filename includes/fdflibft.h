/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdflibft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:55:37 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/08 11:55:38 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDFLIBFT_H
# define FDFLIBFT_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_xyz_coordinates
{
	float		x;
	float		y;
	float		z;
	float		z_orig;
}				t_xyz;

typedef struct	s_mlx_connection
{
	void		*mlx_c;
	void		*mlx_w;
	int			color;
	int			step;
	float		altitude;
	int			pnts_in_row;
	int			cnt_of_rows;
	int			cnt_of_pnts;
	t_xyz		*xyz;
	t_xyz		xyz_mouse[2];
}				t_conn;

typedef struct	s_keys
{
	int			key;
	void		(*f)(t_conn *);
}				t_keys;

int				ft_is_valid(char *av, t_conn *conn);
int				ft_pnts_in_row(char *line, int len);
int				ft_is_correct_symbols(char *line);
void			ft_initialise(t_conn *conn);
void			ft_make_scale(t_conn *conn);
void			ft_make_projection(t_conn *conn);
void			ft_make_position(t_conn *conn);
int				ft_get_coordinates(char *file_name, t_conn *conn);
int				ft_fill_xyz(char *line, t_conn *xyz_c, t_xyz *pnt_num);
int				ft_cross_exit(t_conn *conn);
void			ft_bresenham(t_conn *conn, t_xyz *pnt1, t_xyz *pnt2, int color);
int				ft_draw_line(t_conn *conn);
void			ft_init_xy_line(t_xyz *pnt, int next_pnt, t_conn *conn, int i);
void			ft_fill_usage(t_conn *conn);
int				ft_change_fdf(int key, t_conn *conn);
void			ft_left_mv(t_conn *conn);
void			ft_right_mv(t_conn *conn);
void			ft_up_mv(t_conn *conn);
void			ft_down_mv(t_conn *conn);
void			ft_close_win(t_conn *conn);
void			ft_scale_inc(t_conn *conn);
void			ft_scale_decr(t_conn *conn);
void			ft_altitude_inc(t_conn *conn);
void			ft_altitude_decr(t_conn *conn);
void			ft_change_color(t_conn *conn);
int				ft_mouse_line(int button, int x, int y, t_conn *conn);

#endif
