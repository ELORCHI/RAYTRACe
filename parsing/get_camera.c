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

	pars = g_all_cameras;
	while (pars->next != NULL)
		pars = pars->next;
	pars->next = *tmp;
}

int		result_camera(void)
{
	if (g_nb_error == -1)
		return (-1);
	g_nb_error = 0;
	return (0);
}

int		get_camera(char **params)
{
	t_camera	*tmp;
	static int	i = 0;

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
	if (get_scalar_v(*params, &(tmp->fov)) == -1)
		return (-1);
	if (tmp->fov < 0 || tmp->fov > 180)
		return (ft_exit("ERROR\n FOV must be positive less tha 180 degres"));
	if (i == 0)
		g_all_cameras = tmp;
	else
		add_cameras(&tmp);
	i++;
	return (result_camera());
}
