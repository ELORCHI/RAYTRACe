/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:50:15 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/10 17:50:17 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void get_spheres(t_sphere **sphere, char **params)
{
	t_sphere *tmp;
	t_sphere *pars;

	count_params(*params, 4);
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	tmp->next = NULL;
	params++;
	tmp->orig = get_vector(*params);
	params++;
	get_scalar(*params, &(tmp->rad));
	if (tmp->rad < 0)
		ft_exit("ERROR\n sphere raduis must be positive");
	params++;
	get_color(*params, &(tmp->color));
	if ((*sphere)->next == NULL)
		(*sphere) = tmp;
	else
	{
		pars = (*sphere);
		while (pars->next != NULL)
			pars = pars->next;
		pars = tmp;
	}
} 