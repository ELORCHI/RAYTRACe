/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 10:38:38 by eel-orch          #+#    #+#             */
/*   Updated: 2021/01/21 18:12:27 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H
# include <math.h>
# include <stdbool.h>
# include "mlx.h"
# include <float.h>
# include <stdlib.h>
# define EPSILON 0.0001


typedef struct	s_vector
{
	float x;
	float y;
	float z;
	float w;
}				t_vector;

typedef struct	s_mat
{
	t_vector right;
	t_vector up;
	t_vector forward;
	t_vector trans;
}				t_mat;

typedef struct 	s_reper
{
	t_vector right;
	t_vector up;
	t_vector forward;
}				t_reper;

typedef struct	s_mat4x4
{
	t_vector c1;
	t_vector c2;
	t_vector c3;
	t_vector c4;
}				t_mat4x4;

typedef struct 	s_vec2
{
	float x;
	float y;
}				t_vec2;

typedef struct 	s_vec3
{
	float x;
	float y;
	float z;
}				t_vec3;

typedef struct	s_mat3x3
{
	t_vec3 c1;
	t_vec3 c2;
	t_vec3 c3;
}				t_mat3x3;

typedef struct	s_mat2x2
{
	t_vec2 c1;
	t_vec2 c2;
}				t_mat2x2;

typedef struct	s_shearing
{
	float x_to_y;
	float x_to_z;
	float y_to_x;
	float y_to_z;
	float z_to_x;
	float z_to_y;
}				t_shearing;

typedef struct	s_mlx
{
	void 	*mlx_ptr;
	void 	*win_ptr;
	int		x;
	int		y;
}				t_mlx;

typedef struct  s_data
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

float 		g_intersection[2];

t_data		g_img;

int			create_trgb(t_vector color);

t_vector	add_colors(t_vector color1, t_vector color2);

void		ft_draw(t_mlx canvas, t_vector color, int is_black);

float		magnitude(t_vector vec);

float		floatcmp(float a, float b);

float		determinant_2x2(t_mat2x2 *mat2);

float		dot_product(t_vector vec1, t_vector vec2);

float		cofactor_3x3(t_mat3x3 *mat3, int colomn, int row);

float		minor_3x3(t_mat3x3 *mat3, int colomn, int row);

bool		solve_quadratic(float a, float b, float c);

void		init_reper(void);

void		print_vector(t_vector vec2);

void 		print_mat4(t_mat4x4 mat);

void		print3_vec(t_vec3 vec);

void		scale_mat4(t_mat4x4 *mat, float scalar);

float		determinant_3x3(t_mat3x3 *mat3, int colomn);

float		determinant_4x4(t_mat4x4 *mat4, int colomn);

float		cofactor_4x4(t_mat4x4 *mat4, int colomn, int row, int skip);

bool		inverse_4x4(t_mat4x4 *inverse, t_mat4x4 *mat);

t_vec3		vec3_creat(float a, float b, float c);

t_vector	vec4_creat(float x, float y, float z, float d);

t_vector	point_subb(t_vector	from, t_vector to);

t_vector	subb_vectors(t_vector vec1, t_vector vec2);

t_vector	point_vector(t_vector from, t_vector to);

t_vector	cross_product(t_vector vec1, t_vector vec2);

t_vector	mat_vec_multi(t_mat4x4 mat, t_vector vec);

t_vector	multp_vectors(t_vector vec, float scalar);

t_vector	normaliz(t_vector vec);

t_vector	add_vectors(t_vector vec1, t_vector vec2);

t_vector	color_multp(t_vector color1, t_vector color2);

t_vector	*vector_init(t_vector *vec);

t_vector 	normaliz_color(t_vector color);

t_mat4x4 	look_at();

t_mat4x4	identity_mat(void);

t_mat4x4	scaling(float x, float y, float z);

t_mat4x4	rotation_z(float teta);

t_mat4x4	rotation_x(float teta);

t_mat4x4	mat_multp(t_mat4x4 a, t_mat4x4 b);

t_mat4x4	transpose(t_mat4x4 mat);

t_mat4x4	translation(float x, float y, float z);

t_mat4x4	mat_creat(t_vector v1, t_vector v2, t_vector v3, t_vector v4);

t_mat3x3	mat3_creat(t_vec3 v1, t_vec3 v2, t_vec3 v3);

t_mat3x3	sub_mat4x4(t_mat4x4 *mat4, int colomn, int row);

t_mat2x2	sub_mat3x3(t_mat3x3 *mat3, int colomn, int row);
#endif
