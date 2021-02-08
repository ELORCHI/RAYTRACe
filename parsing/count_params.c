/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 12:10:17 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/01 12:10:40 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool	count_params(char **line, int params_number)
{
	int i;

	i = 0;
	while (*line)
	{
		i++;
		line++;
	}
	if (i == params_number)
		return (true);
	else if (i < params_number)
		printf("ERROR\nfew arguments");
	else
		printf("ERROR\ntoo much arguments");
	exit(EXIT_FAILURE);
}
