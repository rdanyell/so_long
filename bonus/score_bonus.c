/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 16:23:39 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/18 17:19:16 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	display_score(t_info *info)
{
	char	*score;

	score = ft_itoa(info->moves);
	if (!score)
		ft_error("Score malloc error\n", info);
	mlx_string_put(info->mlx, info->win, 10, 15, 2, score);
	free(score);
	return (0);
}
