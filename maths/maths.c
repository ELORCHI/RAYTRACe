/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 04:44:09 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/01 16:29:32 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"
#include <stdlib.h>
#include <stdio.h>
/*
** this function compare two float numbers at epsilon pricision
** its better to do it that way to avoid losing precision
** when just comparing using comparison operators this could happend
*/

float		floatcmp(float a, float b)
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

void 	print_mat4(t_mat4x4 mat)
{
	printf("=============================\n");
	printf("===========MAT4X4============\n");
	printf("%f %f %f %f\n", mat.c1.x ,mat.c2.x, mat.c3.x, mat.c4.x);
	printf("%f %f %f %f\n", mat.c1.y, mat.c2.y, mat.c3.y, mat.c4.y);
	printf("%f %f %f %f\n", mat.c1.z, mat.c2.z, mat.c3.z, mat.c4.z);
	printf("%f %f %f %f\n", mat.c1.w, mat.c2.w, mat.c3.w, mat.c4.w);
	printf("=============================\n");
}

void print_vector(t_vector vec2)
{
	printf("=============================\n");
	printf("==========4DVECTOR===========\n");
	printf("%f\n%f\n%f\n%f\n", vec2.x ,vec2.y, vec2.z, vec2.w);
}

t_vector	point_to_vector(t_vector point)
{
	t_vector vec;

	vec.x = point.x;
	vec.y = point.y;
	vec.z = point.z;
	vec.w = 0;
	return (vec);
}

float		magnitude(t_vector vec)
{
	float magnitude;

	magnitude = sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
	return (magnitude);
}

/*
** check if the division of two floats loses precision
*/

t_vector	normaliz(t_vector vec)
{
	float magnitud;

	magnitud = magnitude(vec);
	if (magnitude > 0)
	{
		magnitud = 1 / magnitud;
		vec.x = vec.x * magnitud;
		vec.y = vec.y * magnitud;
		vec.z = vec.z * magnitud;
		vec.w = 0;
	}
	return (vec);
}


float		dot_product(t_vector vec1, t_vector vec2)
{
	float scalar;

	scalar = vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z + vec1.w * vec2.w;
	return (scalar);
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

t_vector	*vector_init(t_vector *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->z = 0;
	vec->w = 0;
	return (vec);
}

t_vector	point_vector(t_vector from, t_vector to)
{
	t_vector vec;
	vec.x = to.x - from.x;
	vec.y = to.y - from.y;
	vec.z = to.z - from.z;
	vec.w = 0;
	return (vec);
}

/*t_vector	*vector_allo(void)
{
	t_vector *vec;

	vec = (t_vector *)malloc(sizeof(t_vector));
	*vec = vector_init(*vec);
	return (vec);
}*/

t_vector	multp_vectors(t_vector vec, float scalar)
{
	vec.x = vec.x * scalar;
	vec.y = vec.y * scalar;
	vec.z = vec.z * scalar;
	vec.w = 0;
	return (vec);
}

t_vector	add_vectors(t_vector vec1, t_vector vec2)
{
	t_vector summ_vec;

	summ_vec.x = vec1.x + vec2.x;
	summ_vec.y = vec1.y + vec2.y;
	summ_vec.z = vec1.z + vec2.z;
	summ_vec.w = 0;
	return (summ_vec);
}

t_vector	subb_vectors(t_vector vec1, t_vector vec2)
{
	vec2 = multp_vectors(vec2, -1);
	return (add_vectors(vec1, vec2));
}

t_vector	div_vectors(t_vector vec, float scalar)
{
	scalar = 1 / scalar;
	return (multp_vectors(vec, scalar));
}

float	*mini_sort(float *tab)
{
	float tmp;

	tmp = tab[0];
	if (floatcmp(tab[0], tab[1]) > 0)
	{
		tab[0] = tab[1];
		tab[1] = tmp;
		return (tab);
	}
	return (tab);
}

bool	solve_quadratic(float a, float b, float c)
{
	float discr;
	float x;
	float y;
	float min;
	float max;

	discr = (b * b) + (- 4 * a * c);
	if (discr < 0)
		return (false);
	x = 0.5 * (- b - sqrt(discr)) / a;
	y = 0.5 * (- b + sqrt(discr)) / a;
	min = fminf(x, y);
	max = fmaxf(x, y);
	if (min >= 0)
	{
		g_intersection[0] = min;
		g_intersection[1] = max;	
	}
	else if (max >= 0)
	{
		g_intersection[0] = max;
		g_intersection[1] = max;
	}
	else
		return(false);
	return (true);
}

t_vector vec4_creat(float a, float b, float c, float d)
{
	t_vector vec;

	vec.x = a;
	vec.y = b;
	vec.z = c;
	vec.w = d;
	return (vec);
}

t_vec2		vec2_creat(float a, float b)
{
	t_vec2 vec;

	vec.x = a;
	vec.y = b;
	return (vec);
}

t_vector	color_multp(t_vector color1, t_vector color2)
{
	t_vector result;

//	print_vector(color1);
//	printf("jubvdhvbfvbfdvbfdvjfd\n");
	//print_vector(color2);
	result.x = color1.x * color2.x;
	result.y = color1.y * color2.y;
	result.z = color1.z * color2.z;
	result.w = 0;
	//print_vector(result);
	return (result);
}

bool		vect_cmp(t_vector v1, t_vector v2)
{
	if ((v1.x == v1.y) && (v1.y == v2.y) && (v1.z == v2.z))
		return (true);
	return (false);
}

t_vec3		vec3_creat(float a, float b, float c)
{
	t_vec3 vec3;

	vec3.x = a;
	vec3.y = b;
	vec3.z = c;
	return (vec3);
}
/*
** *********************************************** MATRIX ****************************************************
** *********************************************** MATRIX ****************************************************
*/

t_mat4x4	*mat_alloc(void)
{
	t_mat4x4 *mat;

	mat = (t_mat4x4 *)malloc(sizeof(t_mat4x4));
	return (mat);
}

t_vector	 mat_vec_multi(t_mat4x4 mat, t_vector vec)
{
	t_vector result;
	// you need to test this function
	// you may need to traspose the matrix befor multiplaying
	// look for row and colomn major
	result.x = dot_product(mat.c1, vec);
	result.y = dot_product(mat.c2, vec);
	result.z = dot_product(mat.c3, vec);
	result.w = dot_product(mat.c4, vec);
	//result = normaliz(result);
	return (result);
}

t_mat4x4	mat_creat(t_vector v1, t_vector v2, t_vector v3, t_vector v4)
{
	t_mat4x4 new_mat;

	new_mat.c1 = v1;
	new_mat.c2 = v2;
	new_mat.c3 = v3;
	new_mat.c4 = v4;
	return (new_mat);
}

t_mat4x4	mat_multp(t_mat4x4 a, t_mat4x4 b)
{
	t_mat4x4 result;
	a = transpose(a);
	result.c1.x = dot_product(a.c1, b.c1);
	result.c1.y = dot_product(a.c2, b.c1);
	result.c1.z = dot_product(a.c3, b.c1);
	result.c1.w = dot_product(a.c4, b.c1);
	/******/
	result.c2.x = dot_product(a.c1, b.c2);
	result.c2.y = dot_product(a.c2, b.c2);
	result.c2.z = dot_product(a.c3, b.c2);
	result.c2.w = dot_product(a.c4, b.c2);
	/******/
	result.c3.x = dot_product(a.c1, b.c3);
	result.c3.y = dot_product(a.c2, b.c3);
	result.c3.z = dot_product(a.c3, b.c3);
	result.c3.w = dot_product(a.c4, b.c3);
	/******/
	result.c4.x = dot_product(a.c1, b.c4);
	result.c4.y = dot_product(a.c2, b.c4);
	result.c4.z = dot_product(a.c3, b.c4);
	result.c4.w = dot_product(a.c4, b.c4);
	return (result);
}

/***********************************************************************/

t_mat4x4	mat_identity_multp(t_mat4x4 mat)
{
	return (mat);
}

t_mat4x4	transpose(t_mat4x4 mat)
{
	t_mat4x4 result;

	result.c1 = vec4_creat(mat.c1.x ,mat.c2.x, mat.c3.x, mat.c4.x);
	result.c2 = vec4_creat(mat.c1.y ,mat.c2.y, mat.c3.y, mat.c4.y);
	result.c3 = vec4_creat(mat.c1.z ,mat.c2.z, mat.c3.z, mat.c4.z);
	result.c4 = vec4_creat(mat.c1.w ,mat.c2.w, mat.c3.w, mat.c4.w);
	return (result);
}

bool		mat_cmp(t_mat4x4 first, t_mat4x4 second)
{
	if (vect_cmp(first.c1, second.c1) && vect_cmp(first.c2, second.c2) 
			&& vect_cmp(first.c3, second.c3) && vect_cmp(first.c4, second.c4))
		return (true);
	return (false);
}

t_mat2x2	mat2_creat(t_vec2 v1, t_vec2 v2)
{
	t_mat2x2 mat;

	mat.c1 = v1;
	mat.c2 = v2;
	return (mat);
}

t_mat3x3	mat3_creat(t_vec3 v1, t_vec3 v2, t_vec3 v3)
{
	t_mat3x3 mat;

	mat.c1 = v1;
	mat.c2 = v2;
	mat.c3 = v3;
	return (mat);
}

/*t_mat2x2	sub_mat3x3(t_mat3x3 mat3)
{
	t_mat2x2 sub;

	sub.c1 = vec2_creat(mat3.c2.y, mat3.c2.z);
	sub.c2 = vec2_creat(mat3.c3.y, mat3.c3.z);
	return (sub);
}*/

float			element_4x4(t_mat4x4 *mat, int colomn, int row, int skip)
{
	float		element;
	static int	i = 0;
	t_vector	*vec;

	element = 0.1123;
	vec = ((t_vector *)mat + colomn);
	//print_vector(*vec);
	if (i != 0)
		row += i;
	if (row == skip)
	{
		i++;
		row += i;
	}
	if (row == 0)
		element = vec->x;
	else if (row == 1)
		element = vec->y;
	else if (row == 2)
		element = vec->z;
	else if (row == 3)
		element = vec->w;
	if (row == 3)
		i = 0;
	//printf("----%f-----%d---%d-", element, colomn, row);
	return (element);
}

t_mat3x3	sub_mat4x4(t_mat4x4 *mat4, int colomn, int row)
{
	int 		i;
	int			help;
	int			j;
	t_mat3x3	sub;
	t_vec3		vec;
	int t = row;

	i = 0;
	help = 0;
	while (i <= 3)
	{
	    j = -1;
	    if (i == colomn && i < 3)
		    i++;
		vec.x = element_4x4(mat4, i, ++j, row);
		vec.y = element_4x4(mat4, i, ++j, row);
		vec.z = element_4x4(mat4, i, ++j, row);
		if (help == 0)
			sub.c1 = vec;
		else if (help == 1)
			sub.c2 = vec;
		else if (help == 2)
			sub.c3 = vec;
		i++;
		help++;
	}
	return (sub);
}

float		element_3x3(t_mat3x3 *mat, int colomn, int row, int row2)
{
	float		element;
	static	int i = 0;
	t_vec3		*vec;

	element = 0.0456;
	if (colomn == 3)
		colomn--;
	vec = ((t_vec3 *)mat + colomn);
	//print3_vec(*vec);
	if (i != 0)
		row +=i; 
	if (row == row2)
	{
		i++;
		row += i;
	}
	if (row == 0)
		element = vec->x;
	else if (row == 1)
		element = vec->y;
	else if (row == 2)
		element = vec->z;
	if (row == 2)
		i = 0;
	//printf("----%f-----%d----", element, row);
	return (element);
}

t_mat2x2	sub_mat3x3(t_mat3x3 *mat3, int colomn, int row)
{
	int			i;
	int 		j;
	t_mat2x2	sub;
	t_vec2		vec;
	int			help;

	i = 0;
	help = 0;
	while (i <= 2)
	{
		j = -1;
		if (i == colomn && colomn < 2)
			i++;
		vec.x = element_3x3(mat3, i, ++j, row);
		vec.y = element_3x3(mat3, i, ++j, row);
		if (help == 0)
			sub.c1 = vec;
		if (help == 1)
			sub.c2 = vec;
		i++;
		help++;
	}
	return (sub);
}

t_mat4x4	identity_mat(void)
{
	t_mat4x4 mat;

	mat.c1 = vec4_creat(1, 0, 0, 0);
	mat.c2 = vec4_creat(0, 1, 0, 0);
	mat.c3 = vec4_creat(0, 0, 1, 0);
	mat.c4 = vec4_creat(0, 0, 0, 1);
	return (mat);
}

t_mat4x4	translation(float x, float y, float z)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c4 = vec4_creat(x, y, z, 1);
	return (mat);
}

t_mat4x4	scaling(float x, float y, float z)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c1.x = x;
	mat.c2.y = y;
	mat.c3.z = z;
	return (mat);
}

t_mat4x4	rotation_x(float teta)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c2.y = cos(teta);
	mat.c2.z = sin(teta);
	mat.c3.y = -1 * mat.c2.z;
	mat.c3.z = mat.c2.y;
	return (mat);
}

t_mat4x4	rotation_z(float teta)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c1.x = cos(teta);
	mat.c1.y = sin(teta);
	mat.c2.x = -1 * mat.c1.y;
	mat.c2.y = mat.c1.x;
	return (mat);
}

t_mat4x4	rotation_y(float teta)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c1.x = cos(teta);
	mat.c1.z = -1 * sin(teta);
	mat.c3.x = -1 * mat.c1.z;
	mat.c3.z = mat.c1.x;
	return (mat);
}

// this fucntion needs a check
t_mat4x4	shearing(t_shearing shear)
{
	t_mat4x4 mat;

	mat = identity_mat();
	mat.c1.y = shear.y_to_x;
	mat.c1.z = shear.z_to_x;
	mat.c2.x = shear.x_to_y;
	mat.c2.z = shear.z_to_y;
	mat.c3.x = shear.x_to_z;
	mat.c3.y = shear.y_to_z;
	return (mat);
}

void		scale_mat4(t_mat4x4 *mat, float scalar)
{
	t_mat4x4 scaling;

	scaling = identity_mat();
	scaling.c1.x = scalar;
	scaling.c2.y = scalar;
	scaling.c3.z = scalar;
	*mat = mat_multp(*mat, scaling);
}

float		minor_3x3(t_mat3x3 *mat3, int colomn, int row)
{
	float 		minor;
	t_mat2x2	mat2;

	minor = element_3x3(mat3, colomn, row, 110);
	mat2 = sub_mat3x3(mat3, colomn, row);
	minor = minor * determinant_2x2(&mat2);
	return (minor);
}

float		cofactor_3x3(t_mat3x3 *mat3, int colomn, int row)
{
	float 	minore;
	float 	cofactor;
	int		modulo;

	//printf("\ncolomn===[%d]===row===[%d]\n", colomn ,row);
	modulo = (colomn + row) % 2;
	cofactor = 1;
	minore = minor_3x3(mat3, colomn, row);
	if (modulo == 0)
		cofactor = - 1;
	return (minore * cofactor);
}

float		minor_4x4(t_mat4x4 *mat4, int colomn, int row, int skip)
{
	float		minor;
	t_mat3x3	mat3;

	minor = 1;
	if (skip == 1)
		minor = element_4x4(mat4, colomn, row , -7);
	mat3 = sub_mat4x4(mat4, colomn, row);
	minor = minor * determinant_3x3(&mat3, colomn);
	return (minor);
}

float		cofactor_4x4(t_mat4x4 *mat4, int colomn, int row, int skip)
{
	float 	minor;
	float 	cofactor;
	int		modulo;


	//printf("||||||%d||||||", skip);
	modulo = (row + colomn) % 2;
	cofactor = 1;
	//printf("\ncolomn===[%d]===row===[%d]\n", colomn,row);
	minor = minor_4x4(mat4, colomn, row, skip);
	if (modulo == 0)
		cofactor = -1;
	return (minor * cofactor);
}
