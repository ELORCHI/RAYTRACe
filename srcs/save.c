/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 11:22:48 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/17 11:22:49 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/world.h"

void	bmp_initialize(t_bmp *bmp)
{
	int i;
	i = 0;
	bmp->bitcount = 32;
	bmp->imagesize = g_resolution.vsize * g_resolution.hsize * 4;
	bmp->bisize = 40;
	bmp->bfoff_bits = 54;
	bmp->filesize = 54 + bmp->imagesize;
	bmp->bi_planes = 1;
	while (i < 54)
		bmp->header[i++] = 0;
	ft_memcpy(bmp->header, "BM", 2);
	ft_memcpy(bmp->header + 2, &bmp->filesize, 4);
	ft_memcpy(bmp->header + 10, &bmp->bfoff_bits, 4);
	ft_memcpy(bmp->header + 14, &bmp->bisize, 4);
	ft_memcpy(bmp->header + 18, &g_resolution.vsize, 4);
	ft_memcpy(bmp->header + 22, &g_resolution.hsize, 4);
	ft_memcpy(bmp->header + 26, &bmp->bi_planes, 2);
	ft_memcpy(bmp->header + 28, &bmp->bitcount, 2);
	ft_memcpy(bmp->header + 34, &bmp->imagesize, 4);
}

void	create_bmp_file(void)
{
	t_bmp			bmp;
	int				i;
	int				j;
	int				*pixel;
	i = 0;
	bmp_initialize(&bmp);
	j = g_resolution.hsize - 1;
	bmp.fd = open("minirt.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	write(bmp.fd, bmp.header, 54);
	while (j > -1)
	{
		i = 0;
		while (i < g_resolution.vsize)
		{
			bmp.pos = (i + g_resolution.vsize * j);
			pixel = (int *)(g_img->addr) + bmp.pos;
			write(bmp.fd, pixel, 4);
			i++;
		}
		j--;
	}
	close(bmp.fd);
}