/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plans.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:50:03 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/10 17:50:08 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	init_plans(t_plan *plan)
{
	plan->point = (t_vector){0, 0, 0, 0};
	plan->color = (t_vector){0, 0, 0, 0};
	plan->normal = (t_vector){0, 0, 0, 0};
}

void	add_plan(t_plan **plan, t_plan *tmp, int *i)
{
	t_plan *pars;

	if (*i == 0)
		*plan = tmp;
	else
	{
		pars = *plan;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	(*i)++;
}

int		get_plans(t_plan **plan, char **params)
{
	t_plan		*tmp;
	static int	i = 0;

	if (count_params(params, 4) == false)
		return (-1);
	tmp = (t_plan *)malloc(sizeof(t_plan));
	g_plan = 1;
	tmp->next = NULL;
	params++;
	tmp->point = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	if (check_normal(tmp->normal) == false)
		return (-1);
	params++;
	if (get_color(*params, &(tmp->color)) == false)
		return (-1);
	add_plan(plan, tmp, &i);
	if (g_nb_error == -1)
		return (-1);
	return (0);
}
