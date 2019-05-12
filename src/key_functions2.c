/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:00:34 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/09 11:00:35 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdflibft.h"

void	ft_scale_inc(t_conn *conn)
{
	int			i;
	float		scale;

	i = 0;
	scale = 2;
	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	while (i < conn->cnt_of_pnts)
	{
		conn->xyz[i].x = conn->xyz[i].x * scale;
		conn->xyz[i].y = conn->xyz[i].y * scale;
		conn->xyz[i].z = conn->xyz[i].z * scale;
		i++;
	}
	ft_make_position(conn);
	ft_draw_line(conn);
}

void	ft_scale_decr(t_conn *conn)
{
	int			i;
	float		scale;

	i = 0;
	scale = 2;
	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	while (i < conn->cnt_of_pnts)
	{
		conn->xyz[i].x = conn->xyz[i].x / scale;
		conn->xyz[i].y = conn->xyz[i].y / scale;
		conn->xyz[i].z = conn->xyz[i].z / scale;
		i++;
	}
	ft_make_position(conn);
	ft_draw_line(conn);
}

void	ft_altitude_inc(t_conn *conn)
{
	int		i;

	i = 0;
	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	while (i < conn->cnt_of_pnts)
	{
		if (conn->xyz[i].z_orig != (float)0)
			conn->xyz[i].z += conn->xyz[i].z_orig / conn->altitude;
		i++;
	}
	ft_draw_line(conn);
}

void	ft_altitude_decr(t_conn *conn)
{
	int		i;

	i = 0;
	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	while (i < conn->cnt_of_pnts)
	{
		if (conn->xyz[i].z_orig != (float)0)
			conn->xyz[i].z -= conn->xyz[i].z_orig / conn->altitude;
		i++;
	}
	ft_draw_line(conn);
}

void	ft_change_color(t_conn *conn)
{
	static int	i = 0;
	static int	colors[4] = {0xff00ff, 0xffff00, 0x00ffff, 0xff0000};

	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	conn->color = colors[i % 4];
	i += 1;
	ft_draw_line(conn);
}
