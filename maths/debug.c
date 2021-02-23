/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:16:33 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:16:35 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

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

void	print_mat4(t_mat4x4 mat)
{
	printf("=============================\n");
	printf("===========MAT4X4============\n");
	printf("%f %f %f %f\n", mat.c1.x, mat.c2.x, mat.c3.x, mat.c4.x);
	printf("%f %f %f %f\n", mat.c1.y, mat.c2.y, mat.c3.y, mat.c4.y);
	printf("%f %f %f %f\n", mat.c1.z, mat.c2.z, mat.c3.z, mat.c4.z);
	printf("%f %f %f %f\n", mat.c1.w, mat.c2.w, mat.c3.w, mat.c4.w);
	printf("=============================\n");
}
