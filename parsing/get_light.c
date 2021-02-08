
#include "parsing.h"

void	ft_init_light()
{
	g_light->color = (t_vector){0, 0 , 0 ,0};
	g_light->orig = (t_vector){0, 0 , 0 ,0};
	g_light->next = NULL;
}
// not tested yet

void	get_light(char **params)
{
	t_light *tmp;
	t_light *pars;

	count_params(params, 4);
	tmp = (t_light *)malloc(sizeof(t_light));
	params++;
	tmp->orig = get_vector(*params);
	params++;
	get_scalar(*params, &(tmp->ratio));
	if (tmp->ratio < 0)
		ft_exit("ERROR\n light ratio must be positive");
	tmp->next = NULL;
	pars = g_light;
	while (pars->next != NULL)
		pars = pars->next;
	pars->next = tmp;
}