/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 19:23:01 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/08 19:23:02 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdflibft.h"

int		ft_cross_exit(t_conn *conn)
{
	free(conn->xyz);
	exit(0);
	return (0);
}

void	ft_make_scale(t_conn *conn)
{
	float	percent;
	int		i;
	int		points_cpy;

	points_cpy = conn->cnt_of_pnts;
	i = 0;
	while (points_cpy > 200)
	{
		i++;
		points_cpy /= 2;
	}
	i = (i <= 0) ? 1 : i;
	percent = (points_cpy > 200) ? conn->cnt_of_pnts * 0.02 * i : 1;
	conn->step = (points_cpy > 200) ? conn->cnt_of_pnts / percent : 100;
}

int		ft_fill_xyz(char *line, t_conn *conn, t_xyz *pnt_num)
{
	char	**nums;
	int		point;
	int		len;
	int		i;

	i = 0;
	len = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[len])
		len++;
	point = pnt_num->y * len;
	while (nums[i])
	{
		conn->xyz[point].x = (float)((point % len) * conn->step);
		conn->xyz[point].y = (float)(pnt_num->y * conn->step);
		conn->xyz[point].z = (float)(ft_atoi(nums[i]) * conn->altitude);
		conn->xyz[point].z_orig = conn->xyz[point].z;
		free(nums[i]);
		i++;
		point++;
	}
	free(nums);
	return (1);
}

int		ft_get_coordinates(char *file_name, t_conn *conn)
{
	int		fd;
	int		chk_x;
	char	*line;
	t_xyz	xyz;

	chk_x = 0;
	xyz.y = 0;
	xyz.x = 0;
	ft_make_scale(conn);
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		free(conn->xyz);
		return (0);
	}
	while (get_next_line(fd, &line))
	{
		if (!(ft_fill_xyz(line, conn, &xyz)))
		{
			free(conn->xyz);
			return (0);
		}
		xyz.y++;
	}
	close(fd);
	return (1);
}
