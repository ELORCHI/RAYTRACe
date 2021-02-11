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

//need to fix cylinder (diametre and raduis problem)
void get_cylinders(t_cylinder **cylinder, char **params)
{
	t_cylinder *tmp;
	t_cylinder *pars;
	static int i = 0;

	count_params(params, 6);
	params++;
	tmp = (t_cylinder*)malloc(sizeof(t_cylinder));
	tmp->next = NULL;
	tmp->point = get_vector(*params);
	params++;
	tmp->normal = get_vector(*params);
	params++;
	get_color(*params, &(tmp->color));
	params++;
	get_scalar(*params, &(tmp->raduis));
	if (tmp->raduis < 0)
		ft_exit("ERROR\ncylinder's diamertre must be positive");
	params++;
	get_scalar(*params, &(tmp->height));
	if (tmp->height < 0)
		ft_exit("ERROT\ncylinder's hight must be positve");
	if (i == 0)
		*cylinder = tmp;
	else
	{
		pars = *cylinder;
		while (pars->next != NULL)
			pars = pars->next;
		pars->next = tmp;
	}
	i++;
}

// int main()
// {
// 	char *line1 = ft_strdup("cy -50.0,-50,-50 -50,-50,0 10,0,255 14.2 21.42");
// 	char *line2 = ft_strdup("cy 10.0,0.0,20.6 0,0,1.0 0,0,0 12.2 20");

// 	line1 = skip_tabs(&line1);
// 	line2 = skip_tabs(&line2);

// 	char **params1 = ft_split(line1, 32);
// 	char **params2 = ft_split(line2, 32);

// 	t_cylinder *cylinder;
// 	get_cylinders(&cylinder, params1);
// 	get_cylinders(&cylinder, params2);
// 	int i = 0;
// 	while (cylinder != NULL)
// 	{
// 		printf("%d\n", i);
// 		print_vector(cylinder->point);
// 		print_vector(cylinder->normal);
// 		print_vector(cylinder->color);
// 		printf("cylinder->raduis == %f\ncylinder->height == %f\n",cylinder->raduis, cylinder->height);
// 		cylinder = cylinder->next;
// 	}
// 	return (0);
// }