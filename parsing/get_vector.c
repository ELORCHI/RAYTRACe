/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:14:03 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/06 18:14:06 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_vector *get_vector(char *line)
{
	t_vector 	*vec;
	int 		index;

	vec = (t_vector *)malloc(sizeof(t_vector));
	index = 0;
	index += get_scalar(line + index, &(vec->x));
	//printf(" == x index == %d\n", index);
	index += get_scalar(line + index + 1, &(vec->y));
	//printf(" == Y index == %d\n", index);
	index += get_scalar(line + index + 2, &(vec->z));
	//printf("Z");
	return (vec);
}