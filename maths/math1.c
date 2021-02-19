/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:41:12 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/19 18:41:15 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

float	floatcmp(float a, float b)
{
	if (fabs(a - b) >= EPSILON)
		return (b);
	else
		return (a);
}

void	print_mat2(t_mat2x2 mat)
{
	printf("============================\n");
	printf("==========MAT2X2============\n");
	printf("%f %f\n", mat.c1.x, mat.c2.x);
	printf("%f %f\n", mat.c1.y, mat.c2.y);
}

void	print3_vec(t_vec3 vec)
{
	printf("============================\n");
	printf("==========3DVECTOR===========\n");
	printf("%f %f %f\n", vec.x, vec.y, vec.z);
}

void	print2_vec(t_vec3 vec)
{
	printf("=============================\n");
	printf("==========4DVECTOR===========\n");
	printf("%f\n%f\n%f\n", vec.x, vec.y, vec.z);
}

void	print_mat3(t_mat3x3 mat)
{
	printf("=============================\n");
	printf("===========MAT3X3============\n");
	printf("%f %f %f\n", mat.c1.x, mat.c2.x, mat.c3.x);
	printf("%f %f %f\n", mat.c1.y, mat.c2.y, mat.c3.y);
	printf("%f %f %f\n", mat.c1.z, mat.c2.z, mat.c3.z);
	printf("=============================\n");
}
