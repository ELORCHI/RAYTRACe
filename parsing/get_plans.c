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

void init_plans(t_plan *plan)
{
	plan->point = (t_vector){0, 0, 0, 0};
	plan->color = (t_vector){0, 0, 0, 0};
	plan->normal = (t_vector){0, 0, 0, 0};
}

//not tested yet
void get_plan(t_plan **plan, char **params)
{
	t_plan 	*tmp;
	t_plan	*pars;

	count_params(params, 4);
	tmp = (t_plan *)malloc(sizeof(t_plan));
	init_plans(tmp);
	params++;
	tmp->point = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	params++;
	get_color(*params, &(tmp->color));
	if ((*plan)->next == NULL)
		*plan = tmp;
	else
	{
		pars = *plan;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
}