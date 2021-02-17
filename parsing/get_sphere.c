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

int	get_spheres(t_sphere **sphere, char **params)
{
	t_sphere 	*tmp;
	t_sphere 	*pars;
	static int	i = 0;
	
	if (count_params(params, 4) == false);
		return (-1);
	tmp = (t_sphere *)malloc(sizeof(t_sphere));
	tmp->next = NULL;
	params++;
	tmp->orig = get_vector(*params);
	params++;
	if (get_scalar(*params, &(tmp->rad)));
		return (-1);
	if (tmp->rad < 0)
		return (ft_exit("ERROR\n sphere raduis must be positive"));
	params++;
	get_color(*params, &(tmp->color));
	if (i == 0)
		(*sphere) = tmp;
	else
	{
		pars = (*sphere);
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	i = 1;
	if (g_nb_error = -1)
		return (-1);
	return (0);
}

// int main()
// {
// 	char *line = ft_strdup("sp 0,0,20 20 255,0,0");
// 	t_sphere *sphere;
// 	t_sphere *tmp;

// 	line = skip_tabs(&line);
// 	char **params = ft_split(line, 32);
// 	get_spheres(&sphere, params);
// 	print_vector(sphere->orig);
// 	print_vector(sphere->color);
// 	printf("sphere raduis == %f", sphere->rad);

// 	char *line2 = ft_strdup("sp -50,0.3,-0 20 255,0,044");
// 	line2 = skip_tabs(&line2);
// 	char **params2 = ft_split(line2, 32);
// 	get_spheres(&sphere, params2);
// 	sphere = sphere->next;
// 	//tmp = sphere->next;
// 	print_vector(sphere->orig);
// 	print_vector(sphere->color);
// 	printf("sphere raduis == %f", sphere->rad);
// }