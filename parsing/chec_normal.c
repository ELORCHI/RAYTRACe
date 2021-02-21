/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chec_normal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:00:28 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/21 10:00:34 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	check_normal(t_vector normal)
{
	bool result;

	result = true;
	if (normal.x < -1 || normal.x > 1)
		result = false;
	if (normal.y < -1 || normal.y > 1)
		result = false;
	if (normal.z < -1 || normal.y > 1)
		result = false;
	if (result == false)
		printf("ERROR\nnormal vector elements must be in range [-1, 1]\n");
	return (result);
}

bool	check_color_elements(int point)
{
	if (point != 2)
		return (false);
	return (true);
}
