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

// camera previous is not tested
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

// int main()
// {
// 	char *line1 = ft_strdup("c -50,0,20 0,0,0 70");
// 	char *line2 = ft_strdup("c 80,0,20 0,1,0 10");
// 	char *line3 = ft_strdup("c 55,0,20 21,1,0 180");

// 	line1 = skip_tabs(&line1);
// 	line2 = skip_tabs(&line2);
// 	line3 = skip_tabs(&line3);

// 	char **params1 = ft_split(line1, 32);
// 	char **params2 = ft_split(line2, 32);
// 	char **params3 = ft_split(line3, 32);
	
// 	get_camera(params1);
// 	get_camera(params2);
// 	get_camera(params3);
	
// 	int i = 0;
// 	while (g_all_cameras != NULL)
// 	{
// 		printf("%d\n", i);
// 		print_vector(g_all_cameras->orig);
// 		print_vector(g_all_cameras->dir);
// 		printf("FOV = %f", g_all_cameras->fov);
// 		g_all_cameras = g_all_cameras->next;
// 	}
// 	return (0);
// }