/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:09:40 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/01 12:10:48 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	get_ambinet(char **line)
{
	static int amb = 0;

	if (amb = 0)
		amb = 1;
	if (++line == NULL)
		ft_exit("ERROR\n few arguments for ambient light");
		
}
