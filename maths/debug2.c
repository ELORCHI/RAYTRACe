/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:17:42 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:17:57 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

float		floatcmp(float a, float b)
{
	if (fabs(a - b) >= EPSILON)
		return (b);
	else
		return (a);
}

void print_vector(t_vector vec2)
{
	printf("=============================\n");
	printf("==========4DVECTOR===========\n");
	printf("%f\n%f\n%f\n%f\n", vec2.x ,vec2.y, vec2.z, vec2.w);
}