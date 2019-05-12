/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myarovoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:48:30 by myarovoy          #+#    #+#             */
/*   Updated: 2018/06/11 16:48:31 by myarovoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdflibft.h"

void	ft_initialise(t_conn *conn)
{
	conn->color = 0xff0000;
	conn->altitude = 20;
	conn->xyz_mouse[0].x = 0;
	conn->xyz_mouse[0].y = 0;
	conn->mlx_c = mlx_init();
	conn->mlx_w = mlx_new_window(conn->mlx_c, 1920, 1080, "fdf_win");
}

int		ft_pnts_in_row(char *line, int len)
{
	char	**nums;
	int		i;

	i = 0;
	nums = ft_strsplit(line, ' ');
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
	if (len != i && len > 0)
		return (-1);
	return (i);
}

int		ft_is_valid(char *av, t_conn *conn)
{
	int		fd;
	int		len;
	int		ret;
	char	*line;

	len = 0;
	ret = 1;
	conn->cnt_of_rows = -1;
	if ((fd = open(av, O_RDONLY)) < 0)
		return (0);
	while (ret)
	{
		if ((ret = get_next_line(fd, &line)) == -1)
			return (0);
		if (!line && conn->cnt_of_rows == -1)
			return (0);
		if (ret && (len = ft_pnts_in_row(line, len)) == -1)
			return (0);
		conn->cnt_of_rows += 1;
	}
	close(fd);
	conn->pnts_in_row = len;
	conn->cnt_of_pnts = conn->cnt_of_rows * len;
	return (1);
}
