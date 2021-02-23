/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_traingle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:20 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/11 10:32:24 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_tr(t_triangle **tr, t_triangle *tmp, int *i)
{
	t_triangle *pars;

	if (*i == 0)
		*tr = tmp;
	else
	{
		pars = *tr;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	(*i)++;
}

int		get_triangles(t_triangle **trinagle, char **params)
{
	t_triangle	*tmp;
	static int	i = 0;

	if (count_params(params, 5) == false)
		return (-1);
	tmp = (t_triangle *)malloc(sizeof(t_triangle));
	g_tr = 1;
	tmp->next = NULL;
	params++;
	tmp->p1 = get_vector(*params);
	params++;
	tmp->p2 = get_vector(*params);
	params++;
	tmp->p3 = get_vector(*params);
	params++;
	if (get_color(*params, &(tmp->color)) == false)
		return (-1);
	tmp->normal = (t_vector){0, 0, 0, 0};
	add_tr(trinagle, tmp, &i);
	if (g_nb_error == -1)
		return (-1);
	return (0);
}
