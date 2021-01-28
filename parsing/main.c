int init_world(char **param)
{
	while (param != NULL)
	{
			
	}
}

int parssing(int fd, t_world world)
{
	char 	*line;
	char	**param;
	int		i;

	line = "";
	i = get_next_line(fd, &line);
	param = ft_split(line, '32', '	');
	free(line);
	init_world(param);
}