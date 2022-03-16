/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:18:23 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/18 17:06:08 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_animation(t_info *info)
{
	static int	time = 0;

	if (time == 1500)
		put_xpm_image(info->x * SCALE, info->y * SCALE, PLAYER2, info);
	else if (time == 3000)
		put_xpm_image(info->x * SCALE, info->y * SCALE, PLAYER3, info);
	else if (time == 4500)
	{	
		put_xpm_image(info->x * SCALE, info->y * SCALE, PLAYER4, info);
		time = 0;
	}
	time++;
}

void	enemy_animation(t_info *info)
{
	static int	time = 0;
	t_list		*list;
	t_enemy		*enemy;

	list = info->enemies;
	while (list)
	{
		enemy = (t_enemy *)list->content;
		if (time == 3000)
			put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, E1, info);
		else if (time == 4500)
			put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, E2, info);
		else if (time == 6000)
		{
			put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, E3, info);
			time = 0;
		}
		list = list->next;
	}
	time++;
}

void	enemy_runs(t_info *info, t_enemy *enemy)
{
	if (enemy->flag && info->map[enemy->y][enemy->x + 1] == '0')
	{
		info->map[enemy->y][enemy->x + 1] = 'D';
		info->map[enemy->y][enemy->x] = '0';
		put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, FLOOR, info);
		put_xpm_image((enemy->x + 1) * SCALE, enemy->y * SCALE, E1, info);
		enemy->x++;
	}
	else if (enemy->flag)
		enemy->flag = 0;
	else if (!enemy->flag && info->map[enemy->y][enemy->x - 1] == '0')
	{
		info->map[enemy->y][enemy->x - 1] = 'D';
		info->map[enemy->y][enemy->x] = '0';
		put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, FLOOR, info);
		put_xpm_image((enemy->x - 1) * SCALE, enemy->y * SCALE, E1, info);
		enemy->x--;
	}
	else
		enemy->flag = 1;
}

void	move_enemy(t_info *info)
{
	t_list		*list;
	t_enemy		*enemy;
	static int	enemy_time = 0;

	enemy_time++;
	if (enemy_time != 6000)
		return ;
	list = info->enemies;
	while (list)
	{
		enemy = (t_enemy *)list->content;
		enemy_runs(info, enemy);
		list = list->next;
	}
	enemy_time = 0;
}

int	animation(t_info *info)
{
	player_animation(info);
	enemy_animation(info);
	move_enemy(info);
	meet_enemy(info);
	return (0);
}
