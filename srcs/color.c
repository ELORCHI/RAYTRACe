/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:48:33 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/18 11:43:03 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

t_vector normaliz_color(t_vector color)
{
	t_vector new;

	//print_vector(color);
	new.x = fminf(color.x, 1.0f);
	new.y = fminf(color.y, 1.0f);
	new.z = fminf(color.z, 1.0f);
	new.w = 0;
	return (new);
}

int		create_trgb(t_vector color)
{
	int r = floorf(color.x * 255);
	int g = floorf(color.y * 255);
	int b = floorf(color.z * 255);
	return((r << 16) | (g << 8) | b);
}

void	ft_draw(t_mlx canvas, t_vector color, int is_black)
{
	int int_color;

	int_color = create_trgb(color);
	if (is_black == 0)
	{
		mlx_pixel_put(canvas.mlx_ptr, canvas.win_ptr, canvas.x, canvas.y, int_color);
	}
	else
		mlx_pixel_put(canvas.mlx_ptr, canvas.win_ptr, canvas.x, canvas.y, 0);
}
