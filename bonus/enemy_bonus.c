/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:08:45 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/18 17:03:50 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_enemy(void *content)
{
	t_enemy	*enemy;

	enemy = (t_enemy *) content;
	free(enemy);
}

int	count_empty(t_info *info)
{
	int	empty;
	int	i;
	int	j;

	i = 0;
	empty = 0;
	info->enemy = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info-> width)
		{
			if (info->map[i][j] == '0')
				empty++;
			j++;
		}
		i++;
	}
	info->enemy = empty / 15;
	if (info->enemy == 0)
		info->enemy = 1;
	return (0);
}

void	enemy_position(t_info *info, int x, int y)
{
	t_enemy	*enemy;
	t_list	*list;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (enemy == NULL)
		ft_error("Malloc error\n", info);
	enemy->x = x;
	enemy->y = y;
	enemy->flag = 1;
	list = ft_lstnew(enemy);
	if (list == NULL)
		ft_error("Malloc error\n", info);
	ft_lstadd_back(&info->enemies, list);
}

void	add_enemy(t_info *info)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	counter = count_empty(info);
	while (i < info->height)
	{
		j = 0;
		while (j < info-> width)
		{
			if (info->map[i][j] == '0')
				counter++;
			if (counter >= 1 && info->enemy > 0 && (info->map[i][j] == '0' \
				&& info->map[i][j + 1] == '0'))
			{
				info->map[i][j] = 'D';
				counter = -14;
				info->enemy--;
				enemy_position(info, j, i);
			}				
			j++;
		}
		i++;
	}
}

void	meet_enemy(t_info *info)
{
	t_enemy	*enemy;
	t_list	*list;

	list = info->enemies;
	while (list)
	{
		enemy = (t_enemy *)list->content;
		if (info->x == enemy->x && info->y == enemy->y)
		{
			ft_printf("Game over!\n");
			ft_exit(info);
		}
		list = list->next;
	}
}
