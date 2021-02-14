#include "include/world.h"
#include "parsing/parsing.h"

void	set_object(t_world *wolrd, char *line, int last)
{
	char **params;

	line = skip_tabs(line);
	params = ft_split(line, 32);
	else if (ft_strncmp(*params, "A")
		get_ambient();
	else if (ft_strncmp(*params, "R")
		get_resolution();
	else if (ft_strncmp(*params, "s")
		set_spheres(&(world.sphres), params);
	else if (ft_strncmp(*params, "pl")
		set_plans(&(world.plans), params);
	else if (ft_strncmp(*params, "cy")
		set_cylinders(&(world.cylinders), params);
	else if (ft_strncmp(*params, "c")
		set_cameras();
	else if (ft_strncmp(*params, "l")
		set_light();
	else if (ft_strncmp(*params, "tr")
		set_triangle(*params, "sq");
	else
		ft_exit("ERROR\n invalide object");
	//teset if resolution on ambient are missing
}

void	set_world(char *arg)
{
	int 	fd;
	int 	i;
	char 	*line;
	t_world world;

	fd = open(arg, O_RDONLY);
	line = NULL;
	while (i = get_next_line(fd, &line))
	{
		set_object(&world, line, i);
		free(line);
		if (i = 0)
			break;
	}
	free(line);
	render(world);
	free_world(&wolrd);
}

int 	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		save = 0;
		set_world(argv[1]);
	}
	else if (argc == 2)
	{
		is_rt(argv[1]);
		save = 1;
		set_world(argv[1]);
	}
	else
		ft_exit("ERROR\ntoo much arguments");
	exit (EXIT_SUCCES);
	return (0);
}