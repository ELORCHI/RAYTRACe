#include "include/world.h"
#include "parsing/parsing.h"

void	check_mandatory(void)
{
	if (g_is_amb == 0)
		ft_exit("ERROR\nambient light is missing");
	if (g_is_resolution == 0)
		ft_exit("ERROR\nresolution is missing");
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

int		set_object(t_world **world, char **line, int last)
{
	char	**params;
	int		result;

	result = 0;
	*line = skip_tabs(line);
	params = ft_split(*line, 32);
	if (ft_strncmp(*params, (char *)"A", 1))
		result = get_ambient(params);
	else if (ft_strncmp(*params, (char *)"R", 1))
		result = get_resolution(params);
	else if (ft_strncmp(*params, (char *)"s", 1))
		result = get_spheres(&((*world)->sphere), params);
	else if (ft_strncmp(*params, (char *)"pl", 2))
		result = get_plans(&((*world)->plan), params);
	else if (ft_strncmp(*params, (char *)"cy", 2))
		result = get_cylinders(&((*world)->cylinder), params);
	else if (ft_strncmp(*params, (char *)"c", 1))
		result = get_camera(params);
	else if (ft_strncmp(*params, (char *)"l", 1))
		result = get_light(params);
	else if (ft_strncmp(*params, (char *)"tr", 2))
		result = get_triangles(&((*world)->triangle), params);
	else if (ft_strncmp(*params, (char *)"sq", 2))
		result = get_squares(&((*world)->square), params);
	else
		result = ft_exit("ERROR\n invalide object");
	free(*line);
	ft_free(params);
	return (result);
}

void	free_world(t_world **world)
{
	free_spheres(&((*world)->sphere));
	free_planes(&((*world)->plan));
	free_cylinders(&((*world)->cylinder));
	free_squares(&((*world)->square));
	free_triangles(&((*world)->triangle));
	free_globals();
}

void	set_world(char *arg)
{
	int 	fd;
	int 	i;
	char 	*line;
	t_world *world;

	fd = open(arg, O_RDONLY);
	line = NULL;
	while ((i = get_next_line(fd, &line)) || i == 0)
	{
		if (set_object(&world, &line, i) == 0)
			break;
		if (i == 0)
			break;
	}
	check_mandatory();
	render(*world);
	free_world(&world);
}

int 	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		g_save = 0;
		set_world(argv[1]);
	}
	else if (argc == 2)
	{
		is_rt(argv[1]);
		g_save = 1;
		set_world(argv[1]);
	}
	else
		ft_exit("ERROR\ntoo much arguments");
	exit (EXIT_SUCCESS);
	return (0);
}