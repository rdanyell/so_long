/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanyell <rdanyell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:09:41 by rdanyell          #+#    #+#             */
/*   Updated: 2022/02/18 16:41:15 by rdanyell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_height(char *argv, t_info *info)
{
	char	*line;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Can't open file\n", info);
	info->height = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		info->height++;
		free(line);
	}
	if (line)
	{
		free(line);
		line = NULL;
	}
	info->height++;
	close(fd);
}

void	check_folder(char *argv)
{
	char	*folder;
	char	*path;
	int		fd;

	folder = "/";
	path = ft_strjoin(argv, folder);
	fd = open(path, O_RDONLY);
	if (fd != -1)
	{
		ft_printf("Error\nMap error: it's not a file, it's a folder\n");
		exit(1);
	}
	free(path);
	close(fd);
}

void	read_file(char *argv, t_info *info)
{
	int		fd;
	int		height;

	check_folder(argv);
	get_height(argv, info);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("Can't open file\n", info);
	info->map = (char **)malloc(sizeof(char *) * (info->height + 1));
	if (info->map == NULL)
		ft_error("Malloc error", info);
	height = 0;
	while (height < info -> height)
	{
		get_next_line(fd, &info->map[height]);
		height++;
	}
	if (info->map == NULL)
		ft_error("Map error: can't read file", info);
	close(fd);
}

void	check_name(char *name)
{
	int		len;
	char	*endofname;

	len = ft_strlen(name);
	endofname = ft_substr(name, len - 4, 4);
	if (ft_strncmp(endofname, ".ber", 4) != 0)
	{
		free(endofname);
		ft_printf("Error\nMap error: filename error\n");
		exit(1);
	}
	free(endofname);
}

void	parse_map(char *argv, t_info *info)
{
	int	height;

	check_name(argv);
	read_file(argv, info);
	height = 0;
	info->width = ft_strlen(info->map[height]);
	while (height < info->height)
	{
		if (info->width != ft_strlen(info->map[height]))
			ft_error("Map is not rectangular", info);
		height++;
	}
	check_chars(info);
	check_walls(info);
	add_enemy(info);
}
