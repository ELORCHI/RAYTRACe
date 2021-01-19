/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 17:06:29 by eel-orch          #+#    #+#             */
/*   Updated: 2020/12/19 00:00:25 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "ray.h"
#include <stdio.h>
#define HIGHT	1000.0
#define WIDTH	1010
#define FOV 120.0

t_camera creat_cam(t_vector orig, t_vector orient)
{
	t_camera cam;

	cam.orig = orig;
	cam.orient = orient;
	return (cam);
}

/*void print_vector(t_vector vec2)
{
	printf ("%f %f %f %f\n", vec2.x ,vec2.y, vec2.z, vec2.w);
}*/

void	ray_define(int y, int x, t_ray *ray, t_mat4x4 mat)
{
	float ratio;

	/*if (WIDTH >= HIGHT)
		ratio = WIDTH / HIGHT;
	else
		ratio = HIGHT / WIDTH;*/
	ratio = HIGHT / WIDTH;
	ray->dir.x = (2 * ((x + 0.5) / WIDTH) - 1) * tan(FOV / 2 * M_PI / 180);
	ray->dir.y = (-2 * ((y + 0.5) / HIGHT) + 1) * tan(FOV / 2 * M_PI / 180) * ratio;
	ray->dir.z = g_cam.orig.z;
	ray->dir = mat_vec_multi(mat, ray->dir);
}

void 	cam_init(void)
{
	g_cam.orig = vector_creat(10, 4, 0, 1);
	g_cam.orient = normaliz(vector_creat(0, 0, -1, 1));
}

bool		inter(t_ray *ray, t_mat4x4 mat)
{
	t_vector origin_center;
	float a;
	float b;
	float c;

	origin_center = vector_creat(10,4,10,0);
	origin_center = mat_vec_multi(mat, origin_center);
	origin_center = normaliz(point_vector(origin_center, g_cam.orig));
	//print_vector(origin_center);
	a = dot_product(ray->dir, ray->dir);
	b = 2 * dot_product(ray->dir, origin_center);
	c = dot_product(origin_center, origin_center) - 100;
	return (solve_quadratic(a, b, c));
}

int main()
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_mat4x4 	mat;
	t_camera 	cam;
	int			y;
	int			x;
	t_ray		ray;
	t_vector	tmp;

	y = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, HIGHT, WIDTH, "RT");
	cam_init();
	init_reper();
	mat = look_at();
	print_vector(mat.right);
	print_vector(mat.up);
	print_vector(mat.forward);
	print_vector(mat.trans);
	printf("==================\n");
	tmp = mat.trans;
	mat = trasnspose(mat);
	mat.trans = tmp;
	print_vector(mat.right);
	print_vector(mat.up);
	print_vector(mat.forward);
	print_vector(mat.trans);
	while (y <= HIGHT)
	{
		/*if (y == 10)
			return 0;*/
		x = 0;
		while (x <= WIDTH)
		{
			ray_define(y, x, &ray, mat);
			if (inter(&ray, mat) == true)
				mlx_pixel_put(mlx_ptr, win_ptr, y, x, 500);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0);
			x++;
		}
		y++;
	}
	mlx_loop(mlx_ptr);
}
