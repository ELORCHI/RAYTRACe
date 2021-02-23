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

void	add_sphere(t_sphere **sphere, t_sphere *tmp)
{
	t_sphere *pars;

	pars = *sphere;
	while (pars->next != NULL)
		pars = pars->next;
	pars->next = tmp;
}

int		neturn(void)
{
	if (g_nb_error == -1)
		return (-1);
	else
		return (0);
}

int		get_spheres(t_sphere **sphere, char **params)
{
	t_sphere	*tmp;
	static int	i = 0;

	if (count_params(params, 4) == false)
		return (-1);
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	g_sphere = 1;
	tmp->next = NULL;
	params++;
	tmp->orig = get_vector(*params);
	params++;
	if (get_scalar(*params, &(tmp->rad)) == -1)
		return (-1);
	if (tmp->rad < 0)
		return (ft_exit("ERROR\n sphere raduis must be positive"));
	params++;
	if (get_color(*params, &(tmp->color)) == false)
		return (-1);
	if (i == 0)
		(*sphere) = tmp;
	else
		add_sphere(sphere, tmp);
	i++;
	return (neturn());
}
