/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:00:52 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/21 11:00:55 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_init_light(t_light *light)
{
	light->color = (t_vector){0, 0, 0, 0};
	light->orig = (t_vector){0, 0, 0, 0};
	light->ratio = 0.0f;
	light->next = NULL;
}

void	add_light(t_light *tmp, int *i)
{
	t_light	*pars;

	if (*i == 0)
		g_light = tmp;
	else
	{
		pars = g_light;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	(*i)++;
}

int		get_light(char **params)
{
	t_light		*tmp;
	static int	i = 0;

	if (count_params(params, 4) == false)
		return (-1);
	tmp = (t_light *)malloc(sizeof(t_light));
	g_li = 1;
	ft_init_light(tmp);
	params++;
	tmp->orig = get_vector(*params);
	params++;
	if (get_scalar_v(*params, &(tmp->ratio)) == -1)
		return (-1);
	if (tmp->ratio < 0 || tmp->ratio > 1)
		return (ft_exit("ERROR\n light ratio must be in range [0,1]"));
	params++;
	if (get_color(*params, &(tmp->color)) == false)
		return (-1);
	tmp->next = NULL;
	add_light(tmp, &i);
	if (g_nb_error == -1)
		return (-1);
	return (0);
}
