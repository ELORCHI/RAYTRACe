/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:51:24 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/03 15:27:55 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/rt.h"
#include "./maths/maths.c"


/*t_vector g_v1 = vec4_creat(53, 7, 8, 1);
t_vector g_v2 = vec4_creat(11, 2, 3, 4.5);
t_vector g_v3 = vec4_creat(12, 44, 7, 11);
t_vector g_v4 = vec4_creat(14, 0.3, 0.4, 0.5);

t_vec3	g_v31 = vec3_creat(0.55, 0.66, 0.77);
t_vec3	g_v32 = vec3_creat(0.11, 0.12, 0.13);
t_vec3	g_v33 = vec3_creat(0.45, 0.46, 0.45);

t_vec2	g_v21 = vec2_creat(99, 100);
t_vec2	g_v22 = vec2_creat(0, 1);*/

int main()
{
	/*t_vector v1 = vec4_creat(10, 2, 3, 1);
	t_vector v2 = vec4_creat(11, 4, 6, 8);
	t_vector v3 = vec4_creat(23, 24, 25, 7);
	t_vector v4 = vec4_creat(0, 1, 7, 3);
	t_mat4x4 mat = mat_creat(v1, v2, v3, v4);
	print_vector(mat.c1);
	printf("====\n");
	print_mat4(mat);
	t_mat4x4 mat_transpose = transpose(mat);
	print_vector(mat_transpose.c1);
	print_mat4(mat_transpose);*/
/****************************************************/
	/*t_mat2x2 matrix;
	t_vec2 vec1 = vec2_creat(1, 5);
	t_vec2 vec2 = vec2_creat(-3, 2);
	matrix.c1 = vec1;
	matrix.c2 = vec2;
	float deter = determinant_2x2(&matrix);
	printf("%f\n", deter);*/
/***************************************************/
	/*print_mat4(mat);
	t_mat3x3 mat3 = sub_mat4x4(&mat, 2, 2);
	print_mat3(mat3);
	t_mat2x2 mat2 = sub_mat3x3(mat3);
	print_mat2(mat2);*/
	printf("\n\n/**********RAY**TRACING**CHALLENGE**TES***********/\n");
	printf("/*************************************************/\n");

/*	t_vector c1 = vec4_creat(3, 2, 3, 1);
	t_vector c2 = vec4_creat(7, 4, 1, 8);
	t_vector c3 = vec4_creat(2, 2, 5, 7);
	t_vector c4 = vec4_creat(0, 1, 7, 3);
	mat_transpose = mat_creat(c1, c2, c3, c4);
	print_mat4(mat_transpose);
	printf("fohbhvfhvfdhjv fhv fhvfvfjvf hvfvfjk vdfvb;fjv dfvfvfvfvfvf");
	t_mat4x4  mat_mul = mat_multp(mat_transpose, mat);
	print_mat4(mat_mul);
	t_mat3x3 mat3 = sub_mat4x4(&mat_mul, 3, 3);
	print_mat3(mat3);
	t_mat2x2 mmat2 = sub_mat3x3(&mat3, 0,0);
	print_mat2(mmat2);*/
/*******************************************************/
	t_vector g_v1 = vec4_creat(53, 7, 8, 1);	/*creating vectors for 4x4 matrix*/
	t_vector g_v2 = vec4_creat(-9, 2, 3, 4.5);
	t_vector g_v3 = vec4_creat(12, 44, -1.7, 0.11);
	t_vector g_v4 = vec4_creat(14, 0.3, 0.4, 0.5);


	//t_vec3	g_v31 = vec3_creat(0.55, 0.66, 0.77);
	//t_vec3	g_v32 = vec3_creat(0.11, 0.12, 0.13);	/* creating vectors for 3x3 matrix*/
	//t_vec3	g_v33 = vec3_creat(0.22, 0.46, 0.88);


	//t_vec2	g_v21 = vec2_creat(100, 100);			/*creating vectors for 2x2 matrix*/
	//t_vec2	g_v22 = vec2_creat(1, 1);

	//float deter3x3;
	//float deter2x2;
	float deter4x4;

	t_mat4x4	matrice4 = mat_creat(g_v1, g_v2, g_v3, g_v4); /*creating matrices*/
	t_mat4x4	inverse4 = identity_mat();
	//t_mat3x3	matrice3 = mat3_creat(g_v31, g_v32, g_v33);
	//t_mat2x2	matrice2 = mat2_creat(g_v21, g_v22);

	//t_mat3x3	sub_3x3 = sub_mat4x4(&matrice4, 1, 0);	
	//t_mat2x2	sub_2x2 = sub_mat3x3(&matrice3, 1, 2);

	print_mat4(matrice4);	/* printing submatrices*/
	//print_mat3(sub_3x3);
	//print_mat3(matrice3);
	//print_mat2(sub_2x2);
	
	//deter2x2 = determinant_2x2(&matrice2); /* calculating determinant*/
	//deter3x3 = determinant_3x3(&matrice3, 1);
	//deter4x4 = determinant_4x4(&matrice4, 1);
	inverse_4x4(&inverse4, &matrice4);
	int t = 0;
	while (t < 4)
	{
		deter4x4 = determinant_4x4(&matrice4, t);
		//deter3x3 = determinant_3x3(&matrice3, t);
		printf("======\n4x4 determinant [%f]\n", deter4x4);
		t++;
	}
	print_mat4(inverse4);
	//printf("======\n2x2 determinant [%f]\n", deter2x2);
	//printf("======\n3x3 determinant [%f]\n", deter3x3);
	//printf("======\n4x4 determinant [%f]\n", deter4x4);
	//int i;
	//int j;
	//float tes;
	//i = 0;
	//t_mat3x3 test;
	/*while (i < 3)
	{
		j = -1;
		test = sub_mat4x4(&matrice4, 3, i);
		print_mat3(test);
		while (++j < 3)
		{
			printf("%d\n", j);
			tes = determinant_3x3(&test, j);
			printf("%f\n", tes);
		}
		i++;
	}*/
	return 0;
}
