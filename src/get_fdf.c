/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:03:47 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/09 11:03:47 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdflibft.h"

void	ft_fill_usage(t_conn *conn)
{
	mlx_string_put(conn->mlx_c, conn->mlx_w, 1500, 50, conn->color,
											"< ^ > - move");
	mlx_string_put(conn->mlx_c, conn->mlx_w, 1500, 100, conn->color,
											"*     - scale increase");
	mlx_string_put(conn->mlx_c, conn->mlx_w, 1500, 150, conn->color,
											"/     - scale decrease");
	mlx_string_put(conn->mlx_c, conn->mlx_w, 1500, 200, conn->color,
											"+     - altitude increase");
	mlx_string_put(conn->mlx_c, conn->mlx_w, 1500, 250, conn->color,
											"-     - altitude decrease");
	mlx_string_put(conn->mlx_c, conn->mlx_w, 1500, 900, conn->color,
											"sp              - change color");
	mlx_string_put(conn->mlx_c, conn->mlx_w, 1500, 950, conn->color,
											"ms_left click   - draw line");
	mlx_string_put(conn->mlx_c, conn->mlx_w, 1500, 1000, conn->color,
											"esc             - exit");
}

void	ft_init_xy_line(t_xyz *pnt, int next_pnt, t_conn *conn, int i)
{
	pnt[0].x = conn->xyz[i].x;
	pnt[0].y = conn->xyz[i].y - conn->xyz[i].z;
	pnt[0].z = (conn->xyz[i].z_orig + conn->xyz[i + next_pnt].z_orig) / 2;
	pnt[1].x = conn->xyz[i + next_pnt].x;
	pnt[1].y = conn->xyz[i + next_pnt].y - conn->xyz[i + next_pnt].z;
}

int		ft_draw_line(t_conn *conn)
{
	t_xyz	pnt[2];
	int		i;

	i = 0;
	ft_fill_usage(conn);
	while (i < conn->cnt_of_pnts)
	{
		ft_init_xy_line(pnt, 1, conn, i);
		i++;
		if (i % conn->pnts_in_row == 0)
			continue ;
		ft_bresenham(conn, &pnt[0], &pnt[1], conn->color);
	}
	i = 0;
	while (i < conn->cnt_of_pnts - conn->pnts_in_row)
	{
		ft_init_xy_line(pnt, conn->pnts_in_row, conn, i);
		ft_bresenham(conn, &pnt[0], &pnt[1], conn->color);
		i++;
	}
	return (0);
}

void	ft_make_position(t_conn *conn)
{
	int		i;
	float	pos_x;
	float	pos_y;

	i = -1;
	pos_x = conn->xyz[0].x;
	pos_y = conn->xyz[conn->pnts_in_row - 1].y;
	while (++i < conn->cnt_of_pnts)
	{
		conn->xyz[i].x += pos_x * -1;
		conn->xyz[i].y += pos_y * -1;
	}
}

void	ft_make_projection(t_conn *conn)
{
	int		i;

	i = -1;
	while (++i < conn->cnt_of_pnts)
	{
		conn->xyz[i].x = conn->xyz[i].x * 0.5 + conn->xyz[i].y * 0.5;
		conn->xyz[i].y = conn->xyz[i].x * -0.5 + conn->xyz[i].y * 0.5;
	}
	ft_make_position(conn);
}
