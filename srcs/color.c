/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:48:33 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/21 18:09:02 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

t_vector 	normaliz_color(t_vector color)
{
	t_vector new;

	new.x = fminf(color.x, 1);
	new.y =	fminf(color.y, 1);
	new.z = fminf(color.z, 1);
	new.w = 0;
	return (new);
}

t_vector	add_colors(t_vector color1, t_vector color2)
{
	t_vector result;

	result.x = fminf((color1.x + color2.x), 1);
	result.y = fminf((color1.y + color2.y), 1);
	result.z = fminf((color1.z + color2.z), 1);
	return (result);
}

int			create_trgb(t_vector color)
{
	int r = floorf(color.x * 255);
	int g = floorf(color.y * 255);
	int b = floorf(color.z * 255);
	return((r << 16) | (g << 8) | b);
}

//not tested yet
// void		my_mlx_pixel_put(t_mlx canvas, int color)
// {
// 	char *dst;

// 	dst = g_img.addr + (canvas.y * g_img.line_length + canvas.y *(g_img.bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void	ft_draw(t_mlx canvas, t_vector color, int is_black)
{
	int int_color;

	int_color = create_trgb(color);
	if (is_black == 0)
	{
		//my_mlx_pixel_put(canvas.mlx_ptr, canvas.win_ptr, canvas.x, canvas.y, int_color);
		mlx_pixel_put(canvas.mlx_ptr, canvas.win_ptr, canvas.x, canvas.y, int_color);
	}
	else
		mlx_pixel_put(canvas.mlx_ptr, canvas.win_ptr, canvas.x, canvas.y, 0);
		//my_mlx_pixel_put(canvas.mlx_ptr, canvas.win_ptr, canvas.x, canvas.y, 0);
}
