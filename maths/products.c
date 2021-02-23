/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:20:32 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:20:40 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

float		dot_product(t_vector vec1, t_vector vec2)
{
	float sc;

	sc = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
	return (sc);
}

t_vector	cross_product(t_vector vec1, t_vector vec2)
{
	t_vector result;

	result.x = vec1.y * vec2.z - vec2.y * vec1.z;
	result.y = vec1.z * vec2.x - vec1.x * vec2.z;
	result.z = vec1.x * vec2.y - vec1.y * vec2.x;
	result.w = 0;
	return (result);
}
