#include "parsing.h"

bool count_params(char **line, int params_number)
{
	int i;

	while (*line)
	{
		i++;
		line++;
	}
	i++;
	if (i == params_number)
		return (true);
	return (false);
}