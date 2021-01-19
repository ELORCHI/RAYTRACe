/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 23:52:47 by eel-orch          #+#    #+#             */
/*   Updated: 2020/12/18 03:00:36 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "stdio.h"

/*void print_vector(t_vector vec2)
{
	printf ("%f %f %f %f\n", vec2.x ,vec2.y, vec2.z, vec2.w);
}*/
int main()
{
	t_vector vec;
	t_vector vec2;
	float	result;
	t_mat4x4 mat;
	t_camera cam;

	init_reper();
	vec2 = vector_creat (2, 0 , 7 , 0);
	vec = vector_creat(1.0, 7 , 7, 0);
	printf ("%f %f %f %f |%f|\n", vec.x ,vec.y, vec.z, vec2.w, vec.magnitude);
	vec2 = cross_product(vec, vec2);
	printf ("%f %f %f %f |%f|\n", vec2.x ,vec2.y, vec2.z, vec2.w, vec2.magnitude);
	vec2 = normaliz(vec2);
	printf ("%f %f %f %f |%f|\n", vec2.x ,vec2.y, vec2.z, vec2.w, vec2.magnitude);
	result = dot_product(vec2, vec);
	printf("%f\n", result);
	vec2 = vector_creat (2, 0 , 7 , 0);
	vec = vector_creat(1.0, 7 , 7, 0);
	mat = mat_creat(vec, vec2, vector_creat(0 , 2 ,7, 0), vector_creat(0, 0, 0, 1));
	print_vector(mat.right);
	print_vector(mat.up);
	print_vector(mat.forward);
	print_vector(mat.trans);
	vec2 = mat_vec_multi(mat, vector_creat(1,2,3,1));
	printf ("%f %f %f %f\n", vec2.x ,vec2.y, vec2.z, vec2.magnitude);
	vec2 = multp_vectors(vec2, -1);
	printf ("%f %f %f %f\n", vec2.x ,vec2.y, vec2.z, vec2.magnitude);
	vec2 = normaliz(vec2);
	printf ("%f %f %f %f\n", vec2.x ,vec2.y, vec2.z, vec2.magnitude);
	printf("=========================================================================\n");
	cam.orig = vector_creat(1, 7, 10, 1);
	cam.orient = vector_creat(1, 1, 1, 0);
	//print_vector(multp_vectors(cam.orient, -1));
	mat = look_at(cam);
	print_vector(mat.right);
	print_vector(mat.up);
	print_vector(mat.forward);
	print_vector(mat.trans);
	printf("=========================================================================\n");

	int a;
	int b;
	int c;

	a = 1;
	b = 
	return 0;
}
