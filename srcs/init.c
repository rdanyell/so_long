/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:31:17 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/18 17:13:30 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_xpm_image(int x, int y, const char *file, t_info *info)
{
	int	w;
	int	h;

	info->img = mlx_xpm_file_to_image(info->mlx, (char *)file, &w, &h);
	mlx_put_image_to_window(info->mlx, info->win, info->img, x, y);
}

void	put_ground(int x, int y, char c, t_info *info)
{
	if (c == '1')
	{
		put_xpm_image(x, y, FLOOR, info);
		put_xpm_image(x, y, WALL, info);
	}
	else if (c == '0')
	{
		put_xpm_image(x, y, FLOOR, info);
	}
}

void	put_image(int x, int y, char c, t_info *info)
{
	put_ground(x, y, c, info);
	if (c == 'C')
	{
		put_xpm_image(x, y, FLOOR, info);
		put_xpm_image(x, y, COIN, info);
	}
	else if (c == 'P')
	{
		info->x = x / SCALE;
		info->y = y / SCALE;
		put_xpm_image(x, y, FLOOR, info);
		put_xpm_image(x, y, PLAYER1, info);
		info->map[info->y][info->x] = '0';
	}
	else if (c == 'E')
	{
		put_xpm_image(x, y, FLOOR, info);
		put_xpm_image(x, y, EXIT, info);
	}
}

void	draw_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info->width)
		{
			put_image(j * SCALE, i * SCALE, info->map[i][j], info);
			++j;
		}
		++i;
	}
}
