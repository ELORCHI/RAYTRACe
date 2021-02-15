#include "parsing.h"

// not tested yet
void	free_spheres(t_sphere **sphere)
{
	t_sphere *tmp_sphere;

	while (*sphere != NULL)
	{
		tmp_sphere = *sphere;
		*sphere = (*sphere)->next;
		free(tmp_sphere);
	}
}

//this  is not working
// void	free_objects(void **object)
// {
// 	void *tmp_object;
// 	void *tmp_next;

// 	while (*object)
// 	{
// 		tmp_object = *object;
// 		tmp_next = (void *)(*object)->((void *)next)
// 		*object = tmp_next;
// 		free(tmp_object);
// 	}
// }

void	free_triangles(t_triangle **tr)
{
	t_triangle *tmp_tr;

	while (*tr)
	{
		tmp_tr = *tr;
		*tr = (*tr)->next;
		free(tmp_tr);
	}
}

void	free_cylinders(t_cylinder **cylinder)
{
	t_cylinder *tmp_cy;

	while (*cylinder)
	{
		tmp_cy = *cylinder;
		*cylinder = (*cylinder)->next;
		free(tmp_cy);
	}
}

void	free_squares(t_square **square)
{
	t_square *tmp_sq;

	while (*square)
	{
		tmp_sq = *square;
		*square = (*square)->next;
		free(tmp_sq);
	}
}

void	free_planes(t_plan **plan)
{
	t_plan *tmp_plan;

	while (*plan)
	{
		tmp_plan = *plan;
		*plan = (*plan)->next;
		free(tmp_plan);
	}
}
