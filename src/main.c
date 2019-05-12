/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 11:49:40 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/08 11:49:41 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdflibft.h"

int		ft_change_fdf(int key, t_conn *conn)
{
	if (key == 123)
		ft_left_mv(conn);
	if (key == 124)
		ft_right_mv(conn);
	if (key == 126)
		ft_up_mv(conn);
	if (key == 125)
		ft_down_mv(conn);
	if (key == 67)
		ft_scale_inc(conn);
	if (key == 75)
		ft_scale_decr(conn);
	if (key == 69)
		ft_altitude_inc(conn);
	if (key == 78)
		ft_altitude_decr(conn);
	if (key == 49)
		ft_change_color(conn);
	if (key == 53)
		ft_close_win(conn);
	return (0);
}

int		main(int ac, char **av)
{
	t_conn	conn;

	ft_initialise(&conn);
	if (ac != 2)
		write(2, "Usage: ./fdf file\n", 18);
	else
	{
		if (!(ft_is_valid(av[1], &conn)))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		if (!(conn.xyz = (t_xyz*)malloc(sizeof(t_xyz) * conn.cnt_of_pnts)))
			return (0);
		if (!(ft_get_coordinates(av[1], &conn)))
			return (0);
		ft_make_projection(&conn);
		ft_draw_line(&conn);
		mlx_mouse_hook(conn.mlx_w, ft_mouse_line, &conn);
		mlx_hook(conn.mlx_w, 2, 5, ft_change_fdf, &conn);
		mlx_hook(conn.mlx_w, 17, 4, ft_cross_exit, &conn);
		mlx_loop(conn.mlx_c);
	}
	free(conn.xyz);
	return (0);
}
