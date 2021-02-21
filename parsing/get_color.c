/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:09:32 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/06 18:09:37 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int		nb_zeros(char *line, int nb, int index)
{
	int zeros;

	zeros = 0;
	while (line[index] == '0')
	{
		zeros++;
		index++;
	}
	if (zeros == 1 && nb == 0)
		zeros = 0;
	return (zeros);
}

bool	is_color(char *line)
{
	int i;
	int point;

	point = 0;
	i = -1;
	while (line[++i] != '\0')
	{
		if ((ft_isdigit(line[i]) == 1) || line[i] == ',')
		{
			if (line[i] == ',')
			{
				if (i == 0 || line[i + 1] == '\0')
					return (false);
				point++;
				if (point > 2)
					return (false);
				if ((ft_isdigit(line[i - 1]) == 0) ||
				(ft_isdigit(line[i + 1]) == 0))
					return (false);
			}
		}
		else
			return (false);
	}
	return (check_color_elements(point));
}

bool	is_rgb(t_vector rgb)
{
	bool valid;

	valid = true;
	if (rgb.x < 0 || rgb.x > 255)
		valid = false;
	if (rgb.y < 0 || rgb.y > 255)
		valid = false;
	if (rgb.z < 0 || rgb.z > 255)
		valid = false;
	if (valid == false)
	{
		printf("ERROR\ninvalid RGB\nvalue must be an int in range [0,255]\n");
	}
	return (valid);
}

void	norm_color(t_vector *color)
{
	color->x = (color->x / 255);
	color->y = (color->y / 255);
	color->z = (color->z / 255);
	color->w = 0;
}

bool	get_color(char *line, t_vector *color)
{
	int tmp;
	int	int_len;

	if (is_color(line) == false)
	{
		printf("ERROR\ninvalid RGB\nparam must containe three elements\n");
		return (false);
	}
	tmp = atoi(line);
	int_len = ft_int_size(tmp) + nb_zeros(line, tmp, 0);
	color->x = tmp;
	tmp = atoi(line + int_len + 1);
	int_len += 1 + ft_int_size(tmp) + nb_zeros(line, tmp, int_len + 1);
	color->y = tmp;
	tmp = ft_atoi(line + int_len + 1);
	color->z = tmp;
	color->w = 0;
	if (is_rgb(*color) == true)
	{
		norm_color(color);
		return (true);
	}
	else
		return (false);
}
