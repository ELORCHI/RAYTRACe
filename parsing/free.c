#include "parssing.h"

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

//if this is working no need to write a fucntion fot every object
void	free_objects(void **object)
{
	void *tmp_object;

	while (*object)
	{
		tmp_object = *object;
		*object = (*object)->next;
		free(tmp_object);
	}
}