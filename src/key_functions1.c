/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_functions1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 11:00:26 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/09 11:00:27 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdflibft.h"

void	ft_left_mv(t_conn *conn)
{
	int			i;

	i = 0;
	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	while (i < conn->cnt_of_pnts)
	{
		conn->xyz[i].x = conn->xyz[i].x - 100;
		i++;
	}
	ft_draw_line(conn);
}

void	ft_right_mv(t_conn *conn)
{
	int			i;

	i = 0;
	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	while (i < conn->cnt_of_pnts)
	{
		conn->xyz[i].x = conn->xyz[i].x + 100;
		i++;
	}
	ft_draw_line(conn);
}

void	ft_up_mv(t_conn *conn)
{
	int			i;

	i = 0;
	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	while (i < conn->cnt_of_pnts)
	{
		conn->xyz[i].y = conn->xyz[i].y - 100;
		i++;
	}
	ft_draw_line(conn);
}

void	ft_down_mv(t_conn *conn)
{
	int			i;

	i = 0;
	mlx_clear_window(conn->mlx_c, conn->mlx_w);
	while (i < conn->cnt_of_pnts)
	{
		conn->xyz[i].y = conn->xyz[i].y + 100;
		i++;
	}
	ft_draw_line(conn);
}

void	ft_close_win(t_conn *conn)
{
	mlx_destroy_window(conn->mlx_c, conn->mlx_w);
	exit(0);
}
