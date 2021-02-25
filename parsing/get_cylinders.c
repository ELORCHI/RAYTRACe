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

void	add_cylinders(t_cylinder **cylinder, t_cylinder **tmp, int *i)
{
	t_cylinder *pars;

	if (*i == 0)
		*cylinder = *tmp;
	else
	{
		pars = *cylinder;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = *tmp;
	}
	(*i)++;
}

int		result_culinder(void)
{
	if (g_nb_error == -1)
		return (-1);
	return (0);
}

int		check_cylinder(t_cylinder **cy, t_cylinder **tmp, char *params, int *i)
{
	if (get_scalar_v(params, &((*tmp)->height)) == -1)
		return (-1);
	if ((*tmp)->height < 0)
		return (ft_exit("ERROT\ncylinder's hight must be positve"));
	add_cylinders(cy, tmp, i);
	return (result_culinder());
}

int		get_cylinders(t_cylinder **cylinder, char **params)
{
	t_cylinder	*tmp;
	static int	i = 0;

	if (count_params(params, 6) == false)
		return (-1);
	params++;
	tmp = (t_cylinder*)malloc(sizeof(t_cylinder));
	g_cyl = 1;
	tmp->next = NULL;
	tmp->point = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	if (check_normal(tmp->normal) == false)
		return (-1);
	params++;
	if (get_color(*params, &(tmp->color)) == false)
		return (-1);
	params++;
	if (get_scalar_v(*params, &(tmp->raduis)) == -1)
		return (-1);
	if (tmp->raduis < 0)
		return (ft_exit("ERROR\ncylinder's diamertre must be positive"));
	params++;
	return (check_cylinder(cylinder, &tmp, *params, &i));
}
