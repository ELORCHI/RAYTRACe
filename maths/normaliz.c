/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normaliz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:19:02 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:19:06 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

float		magnitude(t_vector vec)
{
	float magn;

	magn = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (magn);
}

t_vector	normaliz(t_vector vec)
{
	float magn;

	magn = magnitude(vec);
	if (magn > 0)
	{
		magn = 1 / magn;
		vec.x = vec.x * magn;
		vec.y = vec.y * magn;
		vec.z = vec.z * magn;
		vec.w = 0;
	}
	return (vec);
}
