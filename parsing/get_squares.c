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

int get_squares(t_square **square, char **params)
{
	t_square 	*tmp;
	t_square 	*pars;
	static int	i = 0;

	if (count_params(params, 5) == false )
		return (-1);
	tmp = (t_square *)malloc(sizeof(t_square));
	g_plan = 1;
	tmp->next = NULL;
	params++;
	tmp->center = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	params++;
	if (get_scalar(*params, &(tmp->side)) == -1)
		return (-1);
	if (tmp->side < 0)
		return (ft_exit("ERROR\n square side must be positive"));
	params++;
	if (get_color(*params ,&(tmp->color)) == false)
		return (-1);
	if (i == 0)
		(*square)= tmp;
	else
	{
		pars = *square;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	i = 1;
	if (g_nb_error == -1)
		return (-1);
	return (0);
}

// int main ()
// {
// 	char *line1 = ft_strdup("sq -10,-10,-10 0,0,1.0 30 42,42,0");
// 	char *line2 = ft_strdup("sq 100,100,40 10,0,1.0 5 0,30,0");

// 	line1 = skip_tabs(&line1);
// 	line2 = skip_tabs(&line2);

// 	char **params1 = ft_split(line1, 32);
// 	char **params2 = ft_split(line2, 32);

// 	t_square *square;
// 	get_squares(&square, params1);
// 	get_squares(&square, params2);
// 	while (square != NULL)
// 	{
// 		print_vector(square->center);
// 		print_vector(square->normal);
// 		printf("side = %f\n",square->side);
// 		print_vector(square->color);
// 		square = square->next;
// 	}
// 	return (0);
// }
