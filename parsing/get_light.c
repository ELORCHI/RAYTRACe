
#include "parsing.h"

void	ft_init_light(t_light *light)
{
	light->color = (t_vector){0, 0 , 0 ,0};
	light->orig = (t_vector){0, 0 , 0 ,0};
	light->ratio = 0.0f;
	light->next = NULL;
}

int	get_light(char **params)
{
	t_light *tmp;
	t_light	*pars;
	static	int i = 0;

	count_params(params, 4);
	tmp = (t_light *)malloc(sizeof(t_light));
	ft_init_light(tmp);
	params++;
	tmp->orig = get_vector(*params);
	params++;
	if (get_scalar(*params, &(tmp->ratio)) == -1)
		return (-1);
	if (tmp->ratio < 0 || tmp->ratio > 1)
		return (ft_exit("ERROR\n light ratio must be in range [0,1]"));
	params++;
	if (get_color(*params, &(tmp->color)) == false)
		return (-1);
	tmp->next = NULL;
	if (i == 0)
		g_light = tmp;
	else
	{
		pars = g_light;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
		i++;
	}
	if (g_nb_error == -1)
		return (-1);
	i++;
	return (0);
}

// int main()
// {
// 	char *line1 = ft_strdup("l 0.2,10.7,9 0.6 255,0,255");
// 	char *line2 = ft_strdup("l 8,10.7,9 0.6 255,0,33");
// 	line1 = skip_tabs(&line1);
// 	line2 = skip_tabs(&line2);
// 	char **params1 = ft_split(line1, 32);
// 	char **params2 = ft_split(line2, 32);
// 	get_light(params1);
// 	get_light(params2);
// 	while (g_light->next != NULL)
// 	{
// 	 	print_vector(g_light->orig);
// 		printf("light ratio == %f\n", g_light->ratio);
// 		print_vector(g_light->color);
// 		g_light = g_light->next;
// 	}
// 	print_vector(g_light->orig);
// 	printf("light ratio == %f\n", g_light->ratio);
// 	print_vector(g_light->color);
// 	return (0);
// }