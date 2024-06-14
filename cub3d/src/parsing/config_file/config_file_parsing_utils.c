/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_file_parsing_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:11:20 by zelhajou          #+#    #+#             */
/*   Updated: 2024/05/02 10:40:43 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_texture(char **texture)
{
	if (*texture)
	{
		free(*texture);
		*texture = NULL;
	}
}

void	free_config(t_config *config)
{
	int	i;

	i = 0;
	free_texture(&config->no_texture);
	free_texture(&config->we_texture);
	free_texture(&config->so_texture);
	free_texture(&config->ea_texture);
	if (config->map)
	{
		while (config->map[i])
		{
			free(config->map[i]);
			config->map[i] = NULL;
			i++;
		}
		free(config->map);
		config->map = NULL;
	}
}

void	remove_newline_character(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
}

int	is_empty_or_whitespace(const char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}

void	print_error_with_caret(const char *line)
{
	int		error_message_len;
	int		i;

	i = 0;
	line = ft_strtrim(line, " \t");
	error_message_len = strlen("Error: Invalid data in map ");
	printf("Error: Invalid data in map '%s'\n", line);
	while (i < error_message_len)
	{
		printf(" ");
		i++;
	}
	printf(ANSI_COLOR_GREEN"\e[1m^\n\e[m "ANSI_COLOR_RESET);
}
