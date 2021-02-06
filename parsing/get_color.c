
#include "parsing.h"

// this is not tested yet

bool	is_color(char *line)
{
	int i = 0;
	int point;

	point = 0;
	i = -1;
	while (line[++i] != '\0')
	{
		if ((ft_isdigit(line[i]) == 1) || line[i] == ',' )
		{
			if ( line[i] == ',')
			{
				if (i == 0 || line[i + 1] == '\0')
					return (false);
				point++;
				if (point > 2)
					return (false);
				if ((ft_isdigit(line[i - 1]) == 0) || (ft_isdigit(line[i + 1]) == 0))
					return (false);
			}
		}
		else
			return (false);
	}
	return (true);
}

bool	is_rgb(t_vector rgb)
{
	if (rgb.x < 0 || rgb.x > 255)
		return (false);
	if (rgb.y < 0 || rgb.y > 255)
		return (false);
	if (rgb.z < 0 || rgb.z > 255)
		return (false);
	return (true);
}

bool	get_color(char *line, t_vector *color)
{
	int			tmp;
	int 		i;

	tmp = atoi(line);
	i = ft_int_size(tmp);
	color->x = tmp;
	tmp = atoi(line + i + 1);
	i += 1 + ft_int_size(tmp);
	color->y = tmp;
	tmp = ft_atoi(line + i + 1);
	color->z = tmp;
	color->w = 0;
	return (is_rgb(*color));
}