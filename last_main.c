/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 11:29:04 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/19 11:29:06 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/world.h"
#include "parsing/parsing.h"

int		set_object2(t_world **world, char **line, char **params)
{
	int result;

	result = 0;
	if (ft_strcmp(*params, "sq") == 0)
		result = get_squares(&((*world)->square), params);
	else if (ft_strcmp(*params, "sp") == 0)
		result = get_spheres(&(*world)->sphere, params);
	else
		result = ft_exit("ERROR\ninvalide object\n");
	free(*line);
	ft_free(params);
	return (result);
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
	else if (ft_strcmp(*params, "A") == 0)
		result = get_ambient(params);
	else if (ft_strcmp(*params, "R") == 0)
		result = get_resolution(params);
	else if (ft_strcmp(*params, "pl") == 0)
		result = get_plans(&((*world)->plan), params);
	else if (ft_strcmp(*params, "cy") == 0)
		result = get_cylinders(&((*world)->cylinder), params);
	else if (ft_strcmp(*params, "c") == 0)
		result = get_camera(params);
	else if (ft_strcmp(*params, "l") == 0)
		result = get_light(params);
	else if (ft_strcmp(*params, "tr") == 0)
		result = get_triangles(&((*world)->triangle), params);
	else
		result = set_object2(world, line, params);
	return (result);
}

void	set_world(char *arg)
{
	int			fd;
	int			i;
	char		*line;
	t_world		*world;

	g_error = 0;
	fd = open(arg, O_RDONLY);
	line = NULL;
	world = (t_world *)malloc(sizeof(t_world));
	init_world(world);
	while ((i = get_next_line(fd, &line)) || i == 0)
	{
		g_error = 0;
		if (i == -1 || set_object(&world, &line) == -1)
		{
			g_error = 1;
			break ;
		}
		if (i == 0)
			break ;
	}
	check_mandatory(i);
	noghmizete(&world);
}

int		main(int argc, char *argv[])
{
	if (argc == 1)
		return (ft_exit("ERROR\nfew arguments"));
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
	exit(EXIT_SUCCESS);
	return (0);
}
