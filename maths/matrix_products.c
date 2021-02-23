/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_products.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 09:26:37 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/23 09:26:52 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>

t_vector	mat_vec_multi(t_mat4x4 mat, t_vector vec)
{
	t_vector result;

	result.x = dot_product(mat.c1, vec);
	result.y = dot_product(mat.c2, vec);
	result.z = dot_product(mat.c3, vec);
	result.w = dot_product(mat.c4, vec);
	return (result);
}

t_mat4x4	mat_multp(t_mat4x4 a, t_mat4x4 b)
{
	t_mat4x4 result;

	a = transpose(a);
	result.c1.x = dot_product(a.c1, b.c1);
	result.c1.y = dot_product(a.c2, b.c1);
	result.c1.z = dot_product(a.c3, b.c1);
	result.c1.w = dot_product(a.c4, b.c1);
	result.c2.x = dot_product(a.c1, b.c2);
	result.c2.y = dot_product(a.c2, b.c2);
	result.c2.z = dot_product(a.c3, b.c2);
	result.c2.w = dot_product(a.c4, b.c2);
	result.c3.x = dot_product(a.c1, b.c3);
	result.c3.y = dot_product(a.c2, b.c3);
	result.c3.z = dot_product(a.c3, b.c3);
	result.c3.w = dot_product(a.c4, b.c3);
	result.c4.x = dot_product(a.c1, b.c4);
	result.c4.y = dot_product(a.c2, b.c4);
	result.c4.z = dot_product(a.c3, b.c4);
	result.c4.w = dot_product(a.c4, b.c4);
	return (result);
}

t_mat4x4	transpose(t_mat4x4 mat)
{
	t_mat4x4 result;

	result.c1 = vec4_creat(mat.c1.x, mat.c2.x, mat.c3.x, mat.c4.x);
	result.c2 = vec4_creat(mat.c1.y, mat.c2.y, mat.c3.y, mat.c4.y);
	result.c3 = vec4_creat(mat.c1.z, mat.c2.z, mat.c3.z, mat.c4.z);
	result.c4 = vec4_creat(mat.c1.w, mat.c2.w, mat.c3.w, mat.c4.w);
	return (result);
}
