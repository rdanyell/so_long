/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:04:18 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/18 17:13:57 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(t_info *info)
{
	ft_printf("Well done! You won with %d moves!\n", info->moves);
	ft_exit(info);
}

void	ft_move(t_info *info, int y, int x)
{
	char	move;

	move = info->map[y][x];
	if (move == 'E' && info->coins == 0)
		win_game(info);
	if (move == '1' || (move == 'E' && info->coins > 0))
		return ;
	else if (move == '0')
	{
		put_xpm_image(info->x * SCALE, info->y * SCALE, FLOOR, info);
		put_xpm_image(x * SCALE, y * SCALE, PLAYER1, info);
	}
	else if (move == 'C')
	{
		put_xpm_image(info->x * SCALE, info->y * SCALE, FLOOR, info);
		put_xpm_image(x * SCALE, y * SCALE, PLAYER1, info);
		info->map[y][x] = '0';
		info->coins--;
	}
	info->y = y;
	info->x = x;
	ft_printf("Moves: %d\n", info->moves++);
}

int	key_hook(int keycode, t_info *info)
{
	if (keycode == KEYRIGHT || keycode == KEYD)
		ft_move(info, info->y, info->x + 1);
	else if (keycode == KEYLEFT || keycode == KEYA)
		ft_move(info, info->y, info->x - 1);
	else if (keycode == KEYUP || keycode == KEYW)
		ft_move(info, info->y - 1, info->x);
	else if (keycode == KEYDOWN || keycode == KEYS)
		ft_move(info, info->y + 1, info->x);
	else if (keycode == 53)
		ft_exit(info);
	return (0);
}
