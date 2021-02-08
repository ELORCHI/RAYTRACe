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

t_vector get_vector(char *line)
{
	int 		index;
	t_vector	vec;
	
	index = 0;
	index += get_scalar(line + index, &(vec.x));
	//printf(" == x index == %d\n", index);
	index += get_scalar(line + index + 1, &(vec.y));
	//printf(" == Y index == %d\n", index);
	index += get_scalar(line + index + 2, &(vec.z));
	vec.w = 0;
	//printf("Z");
	return (vec);
}