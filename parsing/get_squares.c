/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_squares.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:49:54 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/10 17:49:55 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//not tested yet
void get_squares(t_square **square, char **params)
{
	t_square *tmp;
	t_square *pars;

	count_params(params, 5);
	tmp = (t_square *)malloc(sizeof(t_square));
	tmp->next = NULL;
	params++;
	tmp->center = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	params++;
	get_scalar(params, &(tmp->side));
	if (tmp->side < 0)
		ft_exit("ERROR\n square side must be positive");
	params++;
	get_color(params ,&tmp->color);
	if ((*square)->next == NULL)
		(*square)= tmp;
	else
	{
		pars = (*square)->next;
		while (pars->next!= NULL)
			pars = pars->next;
		pars->next = tmp;
	}
}