/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:02:28 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/09 11:02:30 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdflibft.h"

void	ft_bresenham(t_conn *conn, t_xyz *pnt1, t_xyz *pnt2, int color)
{
	int			iter_len;
	t_xyz		len_xy;
	t_xyz		gen;
	t_xyz		kfc;

	kfc.x = (pnt2->x - pnt1->x >= 0) ? 1 : -1;
	kfc.y = (pnt2->y - pnt1->y >= 0) ? 1 : -1;
	len_xy.x = fabsf(pnt2->x - pnt1->x);
	len_xy.y = fabsf(pnt2->y - pnt1->y);
	iter_len = (int)fmax(len_xy.x, len_xy.y) + 1;
	gen.x = pnt1->x;
	gen.y = pnt1->y;
	while (--iter_len)
	{
		mlx_pixel_put(conn->mlx_c, conn->mlx_w, (len_xy.x > len_xy.y) ?
		(int)gen.x : (int)floor(gen.x + 0.5), (len_xy.x > len_xy.y) ?
		(int)floor(gen.y + 0.5) : gen.y, (color - pnt1->z));
		gen.x += (len_xy.x > len_xy.y) ? kfc.x : kfc.x * len_xy.x / len_xy.y;
		gen.y += (len_xy.x > len_xy.y) ? kfc.y * len_xy.y / len_xy.x : kfc.y;
	}
}

int		ft_mouse_line(int button, int x, int y, t_conn *conn)
{
	if (conn->xyz_mouse[0].x == 0 && conn->xyz_mouse[0].y == 0 && button == 1)
	{
		conn->xyz_mouse[0].x = x;
		conn->xyz_mouse[0].y = y;
		mlx_pixel_put(conn->mlx_c, conn->mlx_w, x, y, conn->color);
		return (0);
	}
	else
	{
		conn->xyz_mouse[1].x = x;
		conn->xyz_mouse[1].y = y;
		ft_bresenham(conn, &conn->xyz_mouse[0],
											&conn->xyz_mouse[1], conn->color);
	}
	conn->xyz_mouse[0].x = 0;
	conn->xyz_mouse[0].y = 0;
	conn->xyz_mouse[1].x = 0;
	conn->xyz_mouse[1].y = 0;
	return (0);
}
