/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_globals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:45:43 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/10 14:45:46 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//free camera
//not tested yet
void	free_globals()
{
	t_light *tmp;

	while (g_light != NULL)
	{
		tmp = g_light;
		g_light = g_light->next;
		free(tmp);
	}
	free(g_intersection);
}