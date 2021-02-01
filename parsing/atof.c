#include "libft.h"

float	ft_atof(char *line)
{
	int 	i;
	int 	int_part;
	int 	decimal_part;
	float	nunber;

	i = 0;
	int_part = ft_atoi(*line); // hande the case when a negative number had 0 as int part
	decimal_part = ft_atoi(line + ft_int_size(int_part) + 1);
}