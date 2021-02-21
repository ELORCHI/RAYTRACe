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

void	add_square(t_square **square, t_square *tmp, int *i)
{
	t_square *pars;

	if (*i == 0)
		(*square) = tmp;
	else
	{
		pars = *square;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	i++;
}

int		result_sq(void)
{
	if (g_nb_error == -1)
		return (-1);
	return (0);
}

int		get_squares(t_square **square, char **params)
{
	t_square	*tmp;
	t_square	*pars;
	static int	i = 0;

	if (count_params(params, 5) == false)
		return (-1);
	tmp = (t_square *)malloc(sizeof(t_square));
	g_plan = 1;
	tmp->next = NULL;
	params++;
	tmp->center = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	if (check_normal(tmp->normal) == false)
		return (-1);
	params++;
	if (get_scalar(*params, &(tmp->side)) == -1)
		return (-1);
	if (tmp->side < 0)
		return (ft_exit("ERROR\n square side must be positive"));
	params++;
	if (get_color(*params, &(tmp->color)) == false)
		return (-1);
	add_square(square, tmp, &i);
	return (result_sq());
}
