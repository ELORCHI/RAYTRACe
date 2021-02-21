/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:24:15 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/10 16:24:18 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_cameras(t_camera **tmp)
{
	t_camera *pars;
	t_camera *prev;

	pars = g_all_cameras;
	while (pars->next != NULL)
	{
		prev = pars;
		pars = pars->next;
	}
	(*tmp)->previous = prev;
	pars->next = *tmp;
}

int	get_camera(char **params)
{
	t_camera 	*tmp;
	static int 	i = 0;

	if (count_params(params, 4) == false)
		return (-1);
	tmp = (t_camera *)malloc(sizeof(t_camera));
	g_ca = 1;
	tmp->next = NULL;
	params++;
	tmp->orig = get_vector(*params);
	params++;
	tmp->dir = get_vector(*params);
	if ((check_normal(tmp->dir)) == false)
		return (-1);
	params++;
	if (get_scalar(*params, &(tmp->fov)) == -1)
		return (-1);
	if (tmp->fov < 0 || tmp->fov > 180)
		return (ft_exit("ERROR\n FOV must be positive less tha 180 degres"));
	if (i == 0)
	{
		g_all_cameras = tmp;
		g_all_cameras->previous = NULL;
	}
	else
		add_cameras(&tmp);
	i++;
	if (g_nb_error == -1)
		return (-1);
	g_nb_error = 0;
	return (0);
}
