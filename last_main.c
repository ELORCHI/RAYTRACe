#include "include/world.h"
#include "parsing/parsing.h"


void init_world(t_world *world)
{
	world->sphere = NULL;
	world->plan = NULL;
	world->square = NULL;
	world->triangle = NULL;
	world->cylinder = NULL;
}

void	check_mandatory(void)
{
	if (g_is_amb == 0)
	{
		ft_exit("ERROR\nambient light is missing");
		g_error = 1;
	}
	if (g_is_resolution == 0)
	{
		ft_exit("ERROR\nresolution is missing");
		g_error = 1;
	}
}

void	ft_free(char **to_free)
{
	int i;

	i = 0;
	while (to_free[i] != NULL)
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

int		set_object(t_world **world, char **line)
{
	char	**params;
	int		result;

	result = 0;
	*line = skip_tabs(line);
	params = ft_split(*line, 32);
	if (*params == NULL)
		result = 0;
	else if (ft_strncmp(*params, "A", 1) == 0)
		result = get_ambient(params);
	else if (ft_strncmp(*params, "R", 1) == 0)
		result = get_resolution(params);
	else if (ft_strncmp(*params, "pl", 2) == 0)
		result = get_plans(&((*world)->plan), params);
	else if (ft_strncmp(*params, "cy", 2) == 0)
	{
		result = get_cylinders(&((*world)->cylinder), params);
	}
	else if (ft_strncmp(*params, "c", 1) == 0)
		result = get_camera(params);
	else if (ft_strncmp(*params, "l", 1) == 0)
		result = get_light(params);
	else if (ft_strncmp(*params, "tr", 2) == 0)
		result = get_triangles(&((*world)->triangle), params);
	else if (ft_strncmp(*params, "sq", 2) == 0)
		result = get_squares(&((*world)->square), params);
	else if (ft_strncmp(*params, "sp", 2) == 0)
		result = get_spheres(&(*world)->sphere, params);
	else
		result = ft_exit("ERROR\n invalide object");
	free(*line);
	ft_free(params);
	return (result);
}

void	free_world(t_world *world)
{
	free_spheres(&(world->sphere));
	free_planes(&(world->plan));
	free_cylinders(&(world->cylinder));
	free_squares(&(world->square));
	free_triangles(&(world->triangle));
	free_globals();
}

void	set_world(char *arg)
{
	int 	fd;
	int 	i;
	char 	*line;
	t_world *world;

	g_error = 0;
	fd = open(arg, O_RDONLY);
	line = NULL;
	world = (t_world *)malloc(sizeof(t_world));
	init_world(world);
	while ((i = get_next_line(fd, &line)) || i == 0)
	{
		g_error = 0;
		if (set_object(&world, &line) == -1)
		{
			g_error = 1;
			break;
		}
		if (i == 0)
			break;
	}
	check_mandatory();
	if (g_error == 1)
		free_world(world);
	else
		render(&world);
}

int 	main(int argc, char *argv[])
{
	if (argc == 1)
		return (ft_exit("ERROR\n few arguments"));
	else if (argc == 2)
	{
		is_rt(argv[1]);
		g_save = 0;
		set_world(argv[1]);
	}
	else if (argc == 3)
	{
		is_rt(argv[1]);
		is_save(argv[2]);
		g_save = 1;
		set_world(argv[1]);
	}
	else
		return (ft_exit("ERROR\ntoo much arguments"));
	exit (EXIT_SUCCESS);
	return (0);
}