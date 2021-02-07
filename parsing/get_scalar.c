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

int get_scalar(char *line, float *scalar)
{
	int i;

	i = is_float(line);
	if (i == 0)
	{
		printf("ERROR\ninvalide vector");
		exit(0);
	}
	*scalar = atof(line);
	//printf("%f", *scalar);
	return (i);
}

int main()
{
	char *line = " -0.5,-9.06,0.9";
	float *scalar = (float *)malloc(sizeof(float));
	t_vector *vec;
	int i = 0;
//	i = get_scalar(line, scalar);
	vec = get_vector(line);
	
	print_vector(*vec);
	// if (i == 0)
	// 	printf("ok");
	// else
	// 	printf("i = %d\n%f",i, *scalar);
	return (0);
}