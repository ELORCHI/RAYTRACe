
#include "parsing.h"

void	ft_exit(char *error_message)
{
	printf("%s", error_message);
	exit(1);
}

void	check_resolution()
{
	if (g_resolution.hsize < 0 || g_resolution.vsize < 0)
	{
		ft_exit("ERROR IN RESOLUTION\nresolution must be positive");
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
			return (false);
	}
	return (true);
}

void	get_resolution(char **line)
{
	static int reso = 0;

	if (reso == 0)
		reso = 1;
	else
		ft_exit("resolutio ERROR\none resolution is allowed");
	if (line != NULL)
	{
		if (!is_digit(*line))
			ft_exit("RESOLUTION ERROR\nonly numbers are allowed");
		g_resolution.hsize = ft_atoi(line[1]);
	}
	if (++line != NULL)
	{		
		if (!is_digit(*line))
			ft_exit("RESOLUTION ERROR\nonly numbers are allowed");
		g_resolution.vsize = ft_atoi(line[2]);
	}
	if (++line != NULL)
		ft_exit("RESOLUTION ERROR\nerror to much params for resolution");
	return (check_resolution());
}

int main()
{
	//char *line = "88 99";
	printf("%d\n%d", g_resolution.hsize, g_resolution.vsize);
}