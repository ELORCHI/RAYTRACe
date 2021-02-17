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

int get_plans(t_plan **plan, char **params)
{
	t_plan 		*tmp;
	t_plan		*pars;
	static int 	i = 0;

	if (count_params(params, 4) == false)
		return (-1);
	tmp = (t_plan *)malloc(sizeof(t_plan));
	tmp->next = NULL;
	params++;
	tmp->point = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	params++;
	get_color(*params, &(tmp->color));
	if (i == 0)
		*plan = tmp;
	else
	{
		pars = *plan;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	i++;
	if (g_nb_error = -1)
		return (-1);
	return (0);
}

// int main ()
// {
// 	char *line1 = ft_strdup("pl 10,10,10 0,1.0,0 255,0,225");
// 	char *line2 = ft_strdup("pl 0,0,0 0,1.0,0 255,255,225");

// 	line1 = skip_tabs(&line1);
// 	line2 = skip_tabs(&line2);

// 	char **params1 = ft_split(line1, 32);
// 	char **params2 = ft_split(line2, 32);

// 	t_plan *plan;
// 	get_plans(&plan, params1);
// 	get_plans(&plan, params2);
// 	while (plan != NULL)
// 	{
// 		print_vector(plan->point);
// 		print_vector(plan->normal);
// 		print_vector(plan->color);
// 		plan = plan->next;
// 		printf("======NEXT=====\n");
// 	}
// }