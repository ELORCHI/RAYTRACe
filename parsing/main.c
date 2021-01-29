bool	check_resolution(int hsize, int vsize)
{
	if (hsize < 0 || vsize < 0)
	{
		//("ERROR IN RESOLUTION\nresolution must be positive");
		return (false);
	}
}

bool	is_digit(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] >= 48 && line[i] <= 57)
			i++;
		else
			return (false)
	}
	return (true);
}

void	get_resolution(char **line)
{
	int hsize;
	int	vsize;

	if (line != NULL)
	{
		if (!is_digit(*line))
		{
			//("RESOLUTION ERROR\nonly numbers are allowed");
			//EXIT_FALUIRE
		}
		hsize = ft_atoi(line[1]);
	}
	if (++line != NULL)
	{		
		if (!is_digit(*line))
		{
			//("RESOLUTION ERROR\nonly numbers are allowed");
			//EXIT_FALUIRE
		}
		vsize = ft_atoi(line[2]);
	}
	if (++line != NULL)
		//("RESOLUTION ERROR\nerror to much params for resolution");
	return (check_resolution(hsize, vsize));
}