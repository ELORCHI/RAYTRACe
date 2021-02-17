#include "include/world.h"
#include "parsing/parsing.h"

void	check_mandatory(void)
{
	if (g_is_amb == 0)
		ft_exit("ERROR\nambient light is missing");
	if (g_is_resolution == 0)
		ft_exit("ERROR\nresolution is missing");
}

void	set_object(t_world **world, char **line, int last)
{
	char **params;

	*line = skip_tabs(line);
	params = ft_split(*line, 32);
	if (ft_strncmp(*params, (char *)"A", 1))
		get_ambient(params);
	else if (ft_strncmp(*params, (char *)"R", 1))
		get_resolution(params);
	else if (ft_strncmp(*params, (char *)"s", 1))
		get_spheres(&((*world)->sphere), params);
	else if (ft_strncmp(*params, (char *)"pl", 2))
		get_plans(&((*world)->plan), params);
	else if (ft_strncmp(*params, (char *)"cy", 2))
		get_cylinders(&((*world)->cylinder), params);
	else if (ft_strncmp(*params, (char *)"c", 1))
		get_camera(params);
	else if (ft_strncmp(*params, (char *)"l", 1))
		get_light(params);
	else if (ft_strncmp(*params, (char *)"tr", 2))
		get_triangles(&((*world)->triangle), params);
	else if (ft_strncmp(*params, (char *)"sq", 2))
		get_squares(&((*world)->square), params);
	else
		ft_exit("ERROR\n invalide object");
	free(*line);
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

//set up errno
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
		set_object(&world, &line, i);
		if (i == 0)
			break;
	}
	check_mandatory();
	//check if there is no errors before rendrig
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