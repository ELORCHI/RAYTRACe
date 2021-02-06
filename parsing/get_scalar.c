/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scalar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:15:09 by eel-orch          #+#    #+#             */
/*   Updated: 2021/02/06 18:15:11 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

bool get_scalar(char *line, float *scalar)
{
	if (is_float(line) == false)
	{
		printf("ERROR\ninvalide vector");
		return (false);
	}
	*scalar = atof(line);
	return (true);
}

int main()
{
	char *line = "522";
	float *scalar = (float *)malloc(sizeof(float));
	
	if (get_scalar(line, scalar) == false)
		printf("ok");
	else
		printf("%f", *scalar);
	return (0);
}