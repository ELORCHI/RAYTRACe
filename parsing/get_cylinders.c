/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cylinders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:49:39 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/10 17:49:41 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void get_cylinder(t_cylinder **cylinder, char **params)
{
	t_cylinder *tmp;
	t_cylinder *pars;

	count_params(params, 6);
	params++;
	tmp = (t_cylinder*)malloc(sizeof(t_cylinder));
	tmp->next = NULL;
	tmp->point = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	params++;
	// not finished yet
}