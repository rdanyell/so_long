/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:21:44 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/17 14:39:50 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_line(int fd, char **line)
{
	int		result;
	int		i;
	char	*buffer;

	result = 0;
	i = 0;
	buffer = malloc(100000);
	if (!buffer)
		return (0);
	*line = buffer;
	result = read(fd, &buffer[i], 1);
	while (result > 0 && buffer[i] != '\n')
	{	
		i++;
		result = read(fd, &buffer[i], 1);
	}
	buffer[i] = '\0';
	return (result);
}
