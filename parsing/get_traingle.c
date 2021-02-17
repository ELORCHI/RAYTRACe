/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_traingle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 10:32:20 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/11 10:32:24 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void get_triangles(t_triangle **trinagle, char **params)
{
	t_triangle 	*tmp;
	t_triangle 	*pars;
	static int 	i = 0;
	int 		result;

	if (count_params(params, 5) == false)
		return (-1);
	tmp = (t_triangle *)malloc(sizeof(t_triangle));
	tmp->next = NULL;
	params++;
	tmp->p1 = get_vector(*params);
	params++;
	tmp->p2 = get_vector(*params);
	params++;
	tmp->p3 = get_vector(*params);
	params++;
	get_color(*params, &(tmp->color));
	tmp->normal = (t_vector){0, 0, 0, 0};
	if (i == 0)
		*trinagle = tmp;
	else
	{
		pars = *trinagle;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	i++;
	if (g_nb_error = -1)
		return (-1);
	return (0);
}

// int main()
// {
// 	char *line1 = ft_strdup("tr 10,20,10 10,10,20 20,10,10 0,0,255");
// 	char *line2 = ft_strdup("tr -10,-20,10 10,0,20 33,33,33 1,1,255");

// 	line1 = skip_tabs(&line1);
// 	line2 = skip_tabs(&line2);

// 	char **params1 = ft_split(line1, 32);
// 	char **params2 = ft_split(line2, 32);

// 	t_triangle *tr;
// 	get_triangles(&tr, params1);
// 	get_triangles(&tr, params2);
// 	while (tr != NULL)
// 	{
// 		print_vector(tr->p1);
// 		print_vector(tr->p2);
// 		print_vector(tr->p3);
// 		print_vector(tr->color);
// 		tr = tr->next;
// 	}
// }